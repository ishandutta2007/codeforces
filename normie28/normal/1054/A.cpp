#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	long long x,y,z,t1,t2,t3,n,a[200001],b,i,j,m,el,st;
	cin>>x>>y>>z>>t1>>t2>>t3;
	st=abs(x-y)*t1;
	el=((abs(x-z)+abs(x-y))*t2)+(3*t3);
	if (el<=st) cout<<"YES"; else cout<<"NO";
}