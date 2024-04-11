#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	double a, b ;
	int n;
	cin>>a>>b>>n;
	double time = pow(10,9);
	for(int i=0; i<n; i++)
	{
		double x , y , v ;
		cin>>x>>y>>v;
		double z = sqrt(pow(x-a,2)+pow(y-b,2))/v;
		if(z<time)
		{
			time = z;
		}
	}
	cout<<setprecision(6)<<fixed<<time<<endl;
}