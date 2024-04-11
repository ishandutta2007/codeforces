#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
	int64_t n,m,i,j,sum,needed,hol,remain,k,e,ee,minn,maxx, bot,top, countt=0,counts=0,page,removed=0,temp,op=0,po2for2ttpon[64]; vector <int64_t> d; 
int main()
{
	sum=0;
	cin>>n>>m;
	for (i=1;i<=n;i++) {cin>>k; d.push_back(k); sum+=k;}
	for (i=0;i<n;i++) {bot=n; top=sum-d[i]+1; top=min(top,m); bot=max(bot,m-d[i]+1); if (top-bot+1>0) cout<<d[i]-(top-bot+1); else cout<<d[i]; cout<<' ';}
}