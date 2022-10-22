#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

double x[4],y[4],b1,k1,b2,k2,dx,dy;

double d1,d2;

int main()
{
	cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
	d1=y[1]-y[2];
	d1/=(x[1]-x[2]);
	d2=y[2]-y[3];
	d2/=x[2]-x[3];
	k1=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
	k2=(x[2]-x[3])*(x[2]-x[3])+(y[2]-y[3])*(y[2]-y[3]);
	if(d1==d2||k1!=k2)
		cout<<"no";
	else
		cout<<"yes";
}