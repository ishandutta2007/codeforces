#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t pos;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,x,y,xx,yy,fail, last,po=0, countt=0,counts=0,page,removed=0,temp,op=0,fina[500001],used[500001]; 
	vector <int64_t> f;vector<ob> nds; ob hol; 
vector <int64_t> bui(int64_t x)
{
	vector <int64_t> ii,jj; 
	if (x>=2) {ii=bui(x/2); jj=ii; ii.push_back(x%2); ii.insert(ii.end(),jj.begin(),jj.end());} else {ii.push_back(x);}
	return ii;
}
int main()
{ 
	cin>>a>>b>>x>>y>>xx>>yy;
	op=2*a+1;
	countt=2*a+1; 
	for (i=2;i<=b+x;i++) {if (i<b+1) op++; else if (i>b+1) op--; if (i<yy+1) op++; else if (i>yy+1) op--; countt+=op; } cout<<countt;
}