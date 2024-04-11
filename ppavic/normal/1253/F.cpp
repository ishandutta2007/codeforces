#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

const int N = 3e5 + 500;
const int LOG = 20;

typedef long long ll;
typedef pair < ll , int > pli;

int n, m, q, k;
int v1[N], v2[N], w[N];
vector < pli > v[N], T[N];

ll dis[N];
int tko[N], par[N];
int lca[N][LOG], dep[N];
ll dp_lca[N][LOG];

int pr(int x){
    if(par[x] == x) return x;
    return par[x] = pr(par[x]);
}

void mrg(int x,int y){
    par[pr(x)] = pr(y);
}

void dfs(int x,int lst){
    lca[x][0] = lst; dep[x] = dep[lst] + 1;
    for(pli nxt : T[x]){
        if(nxt.Y == lst) continue;
        dp_lca[nxt.Y][0] = nxt.X;
        dfs(nxt.Y, x);
    }
}

void precompute(){
    for(int j = 1;j < LOG;j++){
        for(int i = 1;i <= n;i++){
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
            dp_lca[i][j] = max(dp_lca[i][j - 1], dp_lca[lca[i][j - 1]][j - 1]);
        }
    }
}

ll get_lca(int x,int y){
    ll ans = 0;
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = LOG - 1;i >= 0;i--)
        if(dep[x] - (1 << i) >= dep[y])
            {ans = max(ans, dp_lca[x][i]); x = lca[x][i];}
    if(x == y) return ans;
    for(int i = LOG - 1;i >= 0;i--)
        if(lca[x][i] != lca[y][i]){
            ans = max(ans, max(dp_lca[x][i], dp_lca[y][i]));
            x = lca[x][i], y = lca[y][i];
        }
    return max(ans, max(dp_lca[x][0], dp_lca[y][0]));
}

void dijkstra(){
    memset(dis, -1, sizeof(dis));
    priority_queue < pli > S;
    for(int i = 1;i <= k;i++)
        S.push({0LL, i}), dis[i] = 0, tko[i] = i, par[i] = i;
    for(;!S.empty();){
        pli cur = S.top(); S.pop();
        for(pli nxt : v[cur.Y]){
            if(dis[nxt.Y] == -1 || dis[cur.Y] + nxt.X <  dis[nxt.Y]){
                dis[nxt.Y] = dis[cur.Y] + nxt.X;
                tko[nxt.Y] = tko[cur.Y];
                S.push({-dis[nxt.Y], nxt.Y});
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0;i < m;i++){
        scanf("%d%d%d", v1 + i, v2 + i, w + i);
        v[v1[i]].PB({w[i], v2[i]});
        v[v2[i]].PB({w[i], v1[i]});
    }
    dijkstra();
    vector < pair < ll, pair < int, int > > >  edg;
    for(int i = 0;i < m;i++){
        if(tko[v1[i]] != tko[v2[i]]){
            edg.PB({dis[v1[i]] + dis[v2[i]] + w[i], {tko[v1[i]], tko[v2[i]]}});
        }
    }
    sort(edg.begin(), edg.end());
    for(pair < ll, pair < int, int > > E : edg){
        if(pr(E.Y.X) == pr(E.Y.Y)) continue;
        mrg(E.Y.X, E.Y.Y); //printf("edge %d %d %lld\n", E.Y.X, E.Y.Y, E.X);
        T[E.Y.X].PB({E.X, E.Y.Y});
        T[E.Y.Y].PB({E.X, E.Y.X});
    }
    dfs(1, 1); precompute();
   // printf("gotov precompute\n");
    for(int i = 0;i < q;i++){
        int x, y; scanf("%d%d", &x, &y);
        printf("%lld\n", get_lca(x, y));
    }
}