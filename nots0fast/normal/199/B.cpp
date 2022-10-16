#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x1,y1,r1,R1,x2,y2,r2,R2;
	cin>>x1>>y1>>r1>>R1>>x2>>y2>>r2>>R2;
	int say = 0;
	double mesafe = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	if(mesafe+r1<=r2|| mesafe+R2<=r1 || mesafe>=r1+R2)
	{
		++say; 
	}
	if(mesafe+R1<=r2 || mesafe+R2<=R1 || mesafe>=R1+R2)
	{
		++say;
	}
	if(mesafe+r2<=r1|| mesafe+R1<=r2 || mesafe>=r2+R1)
	{
		++say; 
	}
	if(mesafe+R2<=r1 || mesafe+R1<=R2 || mesafe>=R1+R2)
	{
		++say;
	}
	cout<<say;
}