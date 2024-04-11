#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int64_t z,n,t,t1,k,fla,i,j,m,count,x,y,min=2000001; vector<char> s,rgb[4]; char c; const char cycle[3]={'R','G','B'};
	cin>>t;
	for (t1=1;t1<=t;t1++)
	{
	cin>>x>>y;
	if (x>=y) { z=y;
	x-=y-1; y=0; 
	if (x>2*z+2) cout<<"NO"<<endl;
	else {
	cout<<"YES"<<endl;
	for (j=2;j<=2*z;j++) cout<<j<<' '<<2<<endl;
	cout<<1<<' '<<2<<endl; x--;
	if (x>0) {cout<<2*z+1<<' '<<2<<endl; x--;}
	if (x>0) {i=1; j=2; while ((x>0)and(j<=2*z)) {cout<<j<<' '<<i<<endl; j+=2; x--;}}
	if (x>0) {i=3; j=2; while ((x>0)and(j<=2*z)) {cout<<j<<' '<<i<<endl; j+=2; x--;}}
}
}
else
{ z=x;
	y-=x-1; x=0; 
	if (y>2*z+2) cout<<"NO"<<endl;
	else {
	cout<<"YES"<<endl;
	for (j=2;j<=2*z;j++) cout<<j<<' '<<3<<endl;
	cout<<1<<' '<<3<<endl; y--;
	if (y>0) {cout<<2*z+1<<' '<<3<<endl; y--;}	
	if (y>0) {i=2; j=2; while ((y>0)and(j<=2*z)) {cout<<j<<' '<<i<<endl; j+=2; y--;}}
	if (y>0) {i=4; j=2; while ((y>0)and(j<=2*z)) {cout<<j<<' '<<i<<endl; j+=2; y--;}}
}
}
}
}