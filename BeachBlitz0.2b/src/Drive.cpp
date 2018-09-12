/*
 * Drive.cpp 
 *
 *  Created on: Aug 19, 2017
 *      Author: Programming
 *      converted: Matt
 */

import Drive.h;
import WPILib.h;
import CANTalon.h;

public void Drive()
{
	enum {CAN0,CAN1,CAN2,CAN3,CAN4,CAN5};
	Fleft = new CANTalon(CAN0);
	Rleft = new CANTalon(CAN1);
	Fright = new CANTalon(CAN4);
	Rright = new CANTalon(CAN5);

	driver = new RobotDrive(Rleft,Fleft,Fright,Rright);
	driver.SetExpiration(50);
	Rleft.SetSafetyEnabled(false);
	Fleft.SetSafetyEnabled(false);
	Rright.SetSafetyEnabled(false);
	Fright.SetSafetyEnabled(false);
	Rleft.SetExpiration(30);
	Fleft.SetExpiration(30);
	Rright.SetExpiration(30);
	Fright.SetExpiration(30);
}
public void AutoArcade(float x, float y)
{
	driver.ArcadeDrive(x, y);
}
public void AutoDrive(float L,float R)
{
	Rleft.Set(L);
	Fleft.Set(L);
	Rright.Set(-R);
	Fright.Set(-R);
}
 public void setDriveControl(XboxController* xbox)
{
	//"GTA5/Halo" configuration
	//driver->ArcadeDrive(-.8*(xbox->GetRawAxis(3)-xbox->GetRawAxis(2)),xbox->GetRawAxis(0));


	//"Ben's configuration"
	 driver.ArcadeDrive(xbox.GetRawAxis(1), xbox.GetRawAxis(4));
}



