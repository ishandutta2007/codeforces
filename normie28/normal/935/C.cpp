#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t pos;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,x,y,fail, last,po=0, countt=0,counts=0,page,removed=0,temp,op=0,fina[500001],used[500001]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
vector <int64_t> bui(int64_t x)
{
	vector <int64_t> ii,jj; 
	if (x>=2) {ii=bui(x/2); jj=ii; ii.push_back(x%2); ii.insert(ii.end(),jj.begin(),jj.end());} else {ii.push_back(x);}
	return ii;
}
int main()
{ 
	cin>>n>>a>>b>>c>>d;
	aa=a; bb=b; xx=c;yy=d;
	dist=sqrt(pow(xx-aa,2)+pow(yy-bb,2));
	if ((dist>n)) {cout<<a<<' '<<b<<' '<<n; return 0;}
	cc=n;
	r=(dist+n)/2;
	if (dist==0) {cc=xx+r; dd=yy;} else {cc=xx+((aa-xx)*r/dist); dd=yy+((bb-yy)*r/dist);}
	cout<<fixed<<setprecision(10)<<cc<<' ';
	cout<<fixed<<setprecision(10)<<dd<<' ';
	cout<<fixed<<setprecision(10)<<r<<' ';
}