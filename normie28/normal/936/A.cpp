#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
	int64_t n,m,i,j,cycles,needed=0,hol,remain,k,e,ee,bot,top,mid, si,sj, countt=0,counts=0,page,removed=0,temp,op=0,po2for2ttpon[64]; long double xx,yy,zz,res;
int main()
{
	cin>>n>>m>>k;
	if (n%m==0) {cout<<fixed<<setprecision(10)<<k; return 0;}
	cycles=m-(n%m); xx=cycles; xx/=2; xx+=n;
	zz=k;
	yy=zz/xx; yy=floor(yy); res=yy*(n+m-(n%m));
	zz-=yy*xx;
	if (zz<=n) res+=zz;
	else {res+=n; zz-=n; res+=zz*2;}
	cout<<fixed<<setprecision(10)<<res;
}