#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
	int64_t n,m,i,j,cycles,needed,hol,remain,k,e,ee,minn,maxx, skillz,sj, countt=0,counts=0,page,removed=0,temp,op=0; vector <int64_t> diffs; long double xx,yy;
int cmp (int64_t x, int64_t y) {return x>y;}
int main()
{
	cin>>n>>k; skillz=k*2; needed=0;
	for (i=1;i<=n;i++) {cin>>m; diffs.push_back(m);}
	sort(diffs.begin(),diffs.end());
	i=0; while(i<n) {if (diffs[i]<=skillz) {skillz=max(skillz,diffs[i]*2); i++;} else {needed++; skillz*=2;}}
	cout<<needed;
}