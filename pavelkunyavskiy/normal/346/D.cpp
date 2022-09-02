//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

const int MAXN = 1100000;

vector<int> gt[MAXN];
int deg[MAXN];
int d[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        gt[b].pb(a);
        deg[a]++;
    }

    for (int i = 0; i < n; i++) 
        d[i] = 1<<30;

    int s,t;
    scanf("%d %d",&s,&t);
    --s,--t;

    d[t] = 0;

    vector<int> q;
    q.push_back(t);
    int ans = 0;

    while (!q.empty()){
        vector<int> nq;

        for (int i = 0; i < (int)q.size(); i++){
            int v = q[i];
//          eprintf("%d\n", v);
            if (d[v] != ans) continue;
            if (v == s){
                printf("%d\n", ans);
                return 0;
            }
            for (int j = 0; j < (int)gt[v].size(); j++){
                int u = gt[v][j];
                deg[u]--;
                assert(deg[u] >= 0);
//              eprintf("%d <- %d[%d]\n",v, u, deg[u]);
                if (deg[u] == 0 && d[u] > d[v]){
                    d[u] = d[v];
                    q.push_back(u);
                } else if (d[u] > d[v] + 1){
                    d[u] = d[v] + 1;
                    nq.push_back(u);
                }
            }
        }

        q = nq;
        ans++;
    }

    printf("-1\n");
    TIMESTAMP(end);
    return 0;
}