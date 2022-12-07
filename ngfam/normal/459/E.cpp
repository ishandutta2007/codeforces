/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

struct edge{
    int u;
    int v;
    int w;
}brid[N];

bool cmp(edge u, edge v){
    return u.w < v.w;
}

int n, m, f[N], g[N];

void MAIN(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        brid[i] = {u, v, w};
    }

    sort(brid + 1, brid + m + 1, cmp);

    int ans = 0;

    for(int i = 1; i <= m; ++i){
        vector < int > change;

        int val = brid[i].w, pos = i;

        while(brid[i].w == val){
            int u = brid[i].u, v = brid[i].v;
            change.push_back(v);
            g[v] = 0;
            ++i;
        }

        i = pos;
        while(brid[i].w == val){
            int u = brid[i].u, v = brid[i].v;
            g[v] = max(g[v], f[u] + 1);
            ++i;
        }

        for(auto u : change){
            f[u] = max(f[u], g[u]);
            ans = max(ans, f[u]);
        }

        --i;
    }

    cout << ans;
}