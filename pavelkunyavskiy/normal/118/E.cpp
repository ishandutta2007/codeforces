#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 310000;

int n;
vector<int> g[MAXN];
int tup[MAXN],tin[MAXN];
int used[MAXN];


vector<pair<int,int> > ans;
int timer;

void dfs(int v,int p){
    used[v] = 1;
    tin[v] = tup[v] = timer++;
    for (int i = 0,sz = g[v].size(); i < sz; i++){
        int to = g[v][i];
        if (to == p)
            continue;
        if (used[to] == 1){
            tup[v] = min(tup[v],tin[to]);
            ans.pb(mp(v,to));
            continue;
        }
        if (used[to] == 2)
           continue;
        ans.pb(mp(v,to));
        dfs(to,v);
        tup[v] = min(tup[v],tup[to]);
        if (tup[to] > tin[v]){
            printf("0\n");
            exit(0);
        }
    }
    used[v] = 2;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int m;
  scanf("%d %d",&n,&m);
  for (int i = 0; i < m; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }

  dfs(0,-1);
  
  for (int i = 0; i < m; i++)
    printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    

  return 0;
}