#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;

vector<int> T[N];

int mx[N];
int dep[N];

void dfs0(int u, int pp){
    mx[u] = 0;
    for(auto x : T[u]){
        if(x != pp){
            dep[x]=dep[u]+1;
            dfs0(x, u);
            mx[u] = max(mx[u],mx[x]+1);
        }
    }
}

int D;
int pivot;

void dfs1(int u, int pp, int mm){
    int cnt = 0;
    if(mm >= D) cnt ++ ;
    int i1 = -1, i2 = -1;
    for(auto x : T[u]){
        if(x == pp) continue;
        if(mx[x] + 1 >= D) cnt ++ ;
        if(i1 == -1 || mx[x] + 1 > mx[i1] + 1){
            i2 = i1;
            i1 = x;
        }
        else if(i2 == -1 || mx[x] + 1 > mx[i2] + 1){
            i2 = x;
        }

    }
    if(cnt >= 3){
        pivot = u;
    }
    int nx;
    for(auto x : T[u]){
        if(x == pp) continue;
        nx = mm;
        if(i1 != -1 && i1 != x) nx = max(nx, mx[i1] + 1);
        if(i2 != -1 && i2 != x) nx = max(nx, mx[i2] + 1);
        dfs1(x, u, nx + 1);
    }
}

const int LOG = 18;

int best[N];
int tin[N];
int tout[N];
int ti;
int up[LOG][N];

void dfs2(int u, int pa){
    tin[u] = ++ti;
    up[0][u] = pa;
    for(int i = 1; i < LOG; i ++) {
        up[i][u]=up[i-1][up[i-1][u]];
    }
    best[u] = u;
    for(auto x : T[u]){
        if(x == pa) continue;
        dep[x] = dep[u] + 1;
        dfs2(x, u);
        if(dep[best[x]] > dep[best[u]]){
            best[u] = best[x];
        }
    }
    tout[u]=ti;
}

bool is_anc(int a, int b){
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int u, int v){
    if(is_anc(u,v)) return u;
    if(is_anc(v,u)) return v;
    for(int i = LOG - 1; i >= 0 ; i -- ){
        if(!is_anc(up[i][u], v)){
            u = up[i][u];
        }
    }
    return up[0][u];
}

int calc(int uu, int vv){
    int vs = lca(uu, vv);
    return dep[uu] + dep[vv] - 2 * dep[vs];
}

int extend(int u, int v, int w){
    int lc = lca(u, v);
    if(dep[w] - dep[lc] >= D){
        int ex = w;
        for(int j = LOG - 1; j >= 0 ; j -- ){
            if((1 << j) & D){
                ex = up[j][ex];
            }
        }
        return ex;
    }
    for(int j = LOG - 1; j >= 0 ; j -- ){
        if(!is_anc(up[j][u], lc)){
            if(dep[up[j][u]] + dep[w] - 2 * dep[lc] >= D){
                u = up[j][u];
            }
        }
    }
    return u;
}

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
    }
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dep[a] = 0;
    dfs0(a, -1);
    D = dep[b];
    pivot = -1;
    dfs1(a, -1, 0);
    if(pivot == -1){
        cout << "NO\n";
        return;
    }
    dep[pivot] = 0;
    ti = 0;
    dfs2(pivot, pivot);
    int ai, bi;
    int nx;
    for(int i = 1; i <= n * 2; i ++ ){
        if(is_anc(a,b) || is_anc(b,a)){
            cout << "YES\n";
            return;
        }
        if(dep[best[a]] - dep[a] >= dep[best[b]] - dep[b]){
            ai = best[a];
            bi = extend(b, a, best[a]);
            a = ai;
            b = bi;
        }
        else{
            bi = best[b];
            ai = extend(a, b, best[b]);
            a = ai;
            b = bi;
        }
    }
    cout << "NO\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}