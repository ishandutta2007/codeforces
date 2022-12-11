#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int LOG = 18;
int u[N], v[N];
bool valid[N];
int par[N];
int up[LOG][N];

int fin(int x){
    if(par[x]==x) return x;
    return par[x]=fin(par[x]);
}

bool unite(int uu, int vv){
    uu=fin(uu);
    vv=fin(vv);
    if(uu==vv) return false;
    par[uu]=vv;
    return true;
}

vector<int> T[N];
int tin[N];
int tout[N];
int tt;
int mm[N];

void dfs(int u, int pa){
    tt ++ ;
    tin[u] = tt;
    mm[tt] = u;
    up[0][u] = pa;
    for(int i = 1; i < LOG; i ++) {
        up[i][u]=up[i-1][up[i-1][u]];
    }
    for(auto x : T[u]){
        if(x == pa) continue;
        dfs(x, u);
    }
    tout[u] = tt;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int n;
int cnt[N];

void add(int li, int ri){
    if(li > ri) return;
    cnt[li] ++ ;
    cnt[ri + 1] -- ;
}

bool sol[N];




int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) par[i] = i;
    for(int i = 1; i <= m ; i ++ ){
        cin >> u[i] >> v[i];
        if(unite(u[i], v[i])){
            valid[i]=true;
            T[u[i]].push_back(v[i]);
            T[v[i]].push_back(u[i]);
        }
        else{
            valid[i]=false;
        }
    }
    dfs(1, 1);
    int pp;
    for(int i = 1; i <= m ; i ++ ){
        if(!valid[i]){
            if(is_anc(u[i], v[i])) swap(u[i], v[i]);
            if(is_anc(v[i], u[i])){
                pp = u[i];
                for(int lg = LOG - 1; lg >= 0 ; lg -- ){
                    if(!is_anc(up[lg][pp], v[i])){
                        pp = up[lg][pp];
                    }
                }
                v[i]=pp;
                add(tin[v[i]], tin[u[i]] - 1);
                add(tout[u[i]] + 1, tout[v[i]]);
            }
            else{
                if(tin[u[i]] > tin[v[i]]) swap(u[i], v[i]);
                //cout << u[i] << " " << v[i] << "\n";
                //cout << tin[u[i]] << " " << tout[u[i]] << " | " << tin[v[i]] << " " << tout[v[i]] << "\n";
                add(1, tin[u[i]] - 1);
                add(tout[u[i]] + 1, tin[v[i]] - 1);
                add(tout[v[i]] + 1, n);
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cnt[i] += cnt[i - 1];
        if(cnt[i] == 0){
            sol[mm[i]] = 1;
        }
    }
    for(int i = 1; i <= n; i ++ ) cout << sol[i];
    return 0;
}