#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
 
using namespace std;
	int64_t n,m,i,j,jj,k,e,minn,maxx, mn,mx, countt=0,counts=0,page,flag[26],removed=0,temp,op=0; long double prob[100001],xx,yy,zz;
int cmp(int64_t a,int64_t b) {return a>b;}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) {cin>>minn>>maxx; mn=minn; mx=maxx; k=(maxx-minn)/m; minn%=m; maxx%=m; if ((minn>maxx)or((maxx==0)or(minn==0))) k++; xx=k; yy=mx-mn+1; prob[i]=xx/yy;} zz=0;
	for (i=1;i<=n-1;i++) zz+=1-((1-prob[i])*(1-prob[i+1])); zz+=1-((1-prob[n])*(1-prob[1]));
	cout<<fixed<<setprecision(10)<<zz*1000*2;
}