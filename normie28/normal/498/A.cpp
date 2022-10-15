#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t pos;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,x,y,xx,yy,fail, last,po=0, countt=0,counts=0,page,removed=0,temp,op=0,fina[500001],used[500001]; 
	vector <int64_t> f;vector<ob> nds; ob hol; 
vector <int64_t> bui(int64_t x)
{
	vector <int64_t> ii,jj; 
	if (x>=2) {ii=bui(x/2); jj=ii; ii.push_back(x%2); ii.insert(ii.end(),jj.begin(),jj.end());} else {ii.push_back(x);}
	return ii;
}
int main()
{ 
	cin>>x>>y>>xx>>yy>>n;
	for (i=1;i<=n;i++) {cin>>a>>b>>c; if (((a*x+b*y+c>0)and(a*xx+b*yy+c<0))or((a*x+b*y+c<0)and(a*xx+b*yy+c>0))) countt++;}
	cout<<countt;
}