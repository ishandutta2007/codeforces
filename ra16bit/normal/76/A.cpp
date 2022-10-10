#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it=(a).begin(); it!=(a).end(); ++it)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxm = 50005;
const int maxn = 256;
const ll infll = 1LL<<62;


vector<pii> t[maxn];
int x[maxm], y[maxm], g[maxm], s[maxm];
int id[maxm];
int n, m, G, S;

bool cmp(int x, int y)
{
  return g[x] < g[y];
}


int p[maxn], pe[maxn];
void dfs(int x, int z)
{
  foreach (it, t[x])
    if (it->first != z)
      p[it->first] = x, pe[it->first] = it->second, dfs(it->first, x);
}

int sum;
int calc(int x, int p)
{  
  int res = 1;
  forn (i, sz(t[x]))
    if (t[x][i].first != p)
      res += calc(t[x][i].first, x), sum = max(sum, s[t[x][i].second]);
  return res;
}

void printt()
{
  printf("tree\n");
  forn (i, n)
  {
    printf("%d : ", i);
    foreach (it, t[i]) printf("(%d, %d) ", it->first, it->second); puts("");
    
  }
}

int main()
{ 
  scanf("%d %d", &n, &m);
  scanf("%d %d", &G, &S);
  forn (i, m) scanf("%d %d %d %d", x+i, y+i, g+i, s+i), --x[i], --y[i];
  forn (i, m) id[i] = i;
  sort(id, id+m, cmp);
  ll res = infll;

//  puts("!!");
  forn (i, m)
  {
    int e = id[i];
    if (x[e] == y[e]) continue;
    ll cur = (ll)G*g[e];
    forn (i, n) p[i] = -1;
    dfs(x[e], -1);    
//    printt();
    if (p[y[e]] != -1)
    {
      int best = 0, ee;
      for (int z=y[e]; p[z]!=-1; z=p[z])
        if (best < s[pe[z]]) best = s[pe[z]], ee = pe[z];
      if (best > s[e])
      {
//        printf("del %d add %d\n", ee, e);
        t[x[ee]].erase(find(t[x[ee]].begin(), t[x[ee]].end(), mp(y[ee], ee)));
        t[y[ee]].erase(find(t[y[ee]].begin(), t[y[ee]].end(), mp(x[ee], ee)));    
         
        t[x[e]].pb(mp(y[e], e));
        t[y[e]].pb(mp(x[e], e));                            
      }  
    }
    else
    {
      t[x[e]].pb(mp(y[e], e));
      t[y[e]].pb(mp(x[e], e));
    }
    sum = 0;
    if (calc(0, -1) == n)
    {
      res = min(res, cur + (ll)S*sum);
    }    
  }
//  printt();
  
  if (res == infll) printf("-1\n");
  else cout << res << endl;
  
 
  return 0;
}