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


const int MAXN = 110000;

vector<int> g[MAXN];
vector<int> c[MAXN];
vector<int> u[MAXN];
int n,m;

int d[MAXN];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
        ::c[a].pb(c);
        ::c[b].pb(c);
    }

    for (int i = 0; i < n; i++){
        int k;
        scanf("%d",&k);
        u[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d",&u[i][j]);
        sort(u[i].begin(),u[i].end());
    }

    memset(d,127,sizeof(d));

    d[0] = 0;
    set<pair<int,int> > s;
    s.insert(mp(0,0));


    for (;!s.empty();){
        int v = s.begin()->second;
        if (v == n-1){
            printf("%d\n",d[n-1]);
            return 0;
        }

        s.erase(s.begin());

        int nd = d[v];

        for (int i = 0; i < (int)u[v].size(); i++)
            if (u[v][i] == nd)
                nd++;

        for (int i = 0; i < (int)g[v].size(); i++){
            int to = g[v][i];
            int len = c[v][i];
            if (d[to] > nd + len){
                s.erase(mp(d[to],to));
                d[to] = nd + len;
                s.insert(mp(d[to],to));
            }
        }
    }

    printf("%d\n",-1);
      
  return 0;
}