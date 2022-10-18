//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
using namespace std;
vector <int> g[1200];
int n,k;
vector < pair <int,int> > c[2];
int sz = 0;
bool cmp(pair<int,int> a,pair<int,int> b) { return a.first > b.first; }

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&k);
  forn(i,n) { int a,b; scanf("%d%d",&a,&b); c[b-1].pb( make_pair(a,i+1) ); }
  sort(c[0].begin(),c[0].end(),cmp);
  sort(c[1].begin(),c[1].end(),cmp);

  
  double res = 0.0;
  forn(i, min(k-1,(int)c[0].size()) ) { res += (double)c[0][i].first/2.0; g[sz].pb(c[0][i].second); sz++; }
  
  if (sz == k-1) 
  { 
	  int m = 2000000000;
	  foran(i,k-1,(int)c[0].size()) { m = min(c[0][i].first,m); g[k-1].pb(c[0][i].second); res += (double)c[0][i].first; }
	  forn(i,(int)c[1].size()) { m = min(c[1][i].first,m); g[k-1].pb(c[1][i].second); res += (double)c[1][i].first; }
	  if ((int)c[0].size() >= k) res -= (double)m/2.0;
  } else
  {
	forn(i,(int)c[1].size()) { g[sz].pb(c[1][i].second); if (sz < k-1) sz++; res += (double)c[1][i].first; }
  }
  
  printf("%.1lf\n",res);
  forn(i,k)
  {
	printf("%d ",(int)g[i].size());
	forn(j,(int)g[i].size()) printf("%d ",g[i][j]);
	puts("");
  }
  return 0;
}