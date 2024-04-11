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
	int64_t z,n,t,t1,k,fla,i,j,m,count,min,a[100001][5],x[100001],y[100001],tar,maxx,maxy,minx,miny; 	maxx=maxy=100000;maxx=maxy=-100000;
	cin>>t;
	for (t1=1;t1<=t;t1++)
	{
	maxx=maxy=100000;minx=miny=-100000;
	cin>>n; count=0; 
	for (i=1;i<=n;i++)
	{cin>>x[i]>>y[i];  for (j=1;j<=4;j++) cin>>a[i][j];
	if (a[i][1]==0) if (minx<x[i]) minx=x[i];
	if (a[i][2]==0) if (maxy>y[i]) maxy=y[i];
	if (a[i][3]==0) if (maxx>x[i]) maxx=x[i];
	if (a[i][4]==0) if (miny<y[i]) miny=y[i];
}
	//cout<<minx<<' '<<maxx<<' '<<miny<<' '<<maxy<<endl;
	if ((minx>maxx) or (miny>maxy)) cout<<0<<endl; else cout<<1<<' '<<minx<<' '<<miny<<endl;
}
}