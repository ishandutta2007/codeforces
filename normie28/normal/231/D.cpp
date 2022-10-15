#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t pos;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,e,f,x,y,z,fail, last,po=0, countt=0,counts=0,page,removed=0,temp,op=0,fina[500001],used[500001]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
vector <int64_t> bui(int64_t x)
{
	vector <int64_t> ii,jj; 
	if (x>=2) {ii=bui(x/2); jj=ii; ii.push_back(x%2); ii.insert(ii.end(),jj.begin(),jj.end());} else {ii.push_back(x);}
	return ii;
}
int main()
{ 	cin>>aa>>bb>>cc;
	cin>>x>>y>>z;
	cin>>a>>b>>c>>d>>e>>f;
	if (bb>y) po+=b;
	if (bb<0) po+=a;
	if (cc>z) po+=d;
	if (cc<0) po+=c;
	if (aa>x) po+=f;
	if (aa<0) po+=e;
	cout<<po;
}