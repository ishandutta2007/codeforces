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
	cin>>a>>b>>i>>c>>d>>j;
	aa=a; bb=b; xx=c;yy=d;
	dist=sqrt(pow(xx-aa,2)+pow(yy-bb,2));
	if (dist-i-j<0) if (i<j) if (dist+i<j) cout<<fixed<<setprecision(10)<<(j-(dist+i))/2; else cout<<0;
	else if (dist+j<i) cout<<fixed<<setprecision(10)<<(i-(dist+j))/2; else cout<<0;
	else cout<<fixed<<setprecision(10)<<abs((dist-i-j))/2;
}