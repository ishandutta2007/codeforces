#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair

#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int LOG=  18;
int A[N];
vector<int> pr[N];
vector<int> nd[N];

vector<int> T[N];
int tin[N];
int tout[N];
int up[LOG][N];
int dist[N];
int tt;
void dfs(int u, int pa){
    tt ++ ;
    tin[u] = tt;
    up[0][u] = pa;
    for(int i = 1; i < LOG; i ++ ){
        up[i][u] = up[i-1][up[i-1][u]];
    }
    for(auto x : T[u]){
        if(x == pa) continue;
        dist[x] = dist[u] + 1;
        dfs(x, u);
    }

    tout[u] = tt;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_anc(u, v)) return u;
    for(int lg = LOG - 1; lg >= 0 ; lg -- ){
        if(!is_anc(up[lg][u], v)){
            u = up[lg][u];
        }
    }
    return up[0][u];
}
vector<int> G[N];

int subt[N];
const int MOD = 998244353;
int res = 0;
int mm;

int mult(int x, int y){
    return (x * 1ll * y) % MOD;
}

int f(int n){
    if(n % 2 == 0){
        return ((n/2) * 1ll * (n - 1)) % MOD;
    }
    else{
        return (((n-1)/2) * 1ll * n) % MOD;
    }
}
int p;
void dfs2(int u, int pp){
    if(A[u] % p == 0) subt[u] = 1; 
    else subt[u] = 0;
    int ww;
    for(auto x : G[u]){
        if(x != pp) {
            dfs2(x, u);
            subt[u] += subt[x];
            
            ww = mult(subt[x], f(mm - subt[x]));
            
            ww = (ww + mult(mm - subt[x], f(subt[x]))) % MOD;
            ww = mult(ww, dist[x] - dist[u]);
            res = (res + ww) % MOD;
        }
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int i = 2; i < N; i  ++ ){
        if(pr[i].empty()){
            for(int j = i; j < N; j += i){
                pr[j].push_back(i);
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(auto x : pr[A[i]]){
            nd[x].push_back(i);
        }
    }
    int uu, vv;
    for(int i = 1; i < n; i ++ ){
        cin >> uu >> vv;
        T[uu].push_back(vv);
        T[vv].push_back(uu);
    }
    dfs(1, 1);
    int lc;
    for(int i = 2; i < N; i ++) {
        if(!nd[i].empty()){
            p = i;
            vector<pii> lis;
            for(auto x : nd[i]){
                lis.push_back(mp(tin[x], x));
            }
            sort(lis.begin(), lis.end());
            vector<pii> nw;
            for(int i = 0 ; i + 1 < lis.size(); i ++ ){
                lc = lca(lis[i].se, lis[i + 1].se);
                nw.push_back(mp(tin[lc], lc));
            }
            for(auto x : lis)
                nw.push_back(x);
            sort(nw.begin(), nw.end());
            nw.resize(unique(nw.begin(), nw.end()) - nw.begin());
            vector<int> par;
            for(auto x : nw){
                while(!par.empty() && !is_anc(par.back(), x.se)){
                    par.pop_back();
                }
                if(!par.empty())
                    G[par.back()].push_back(x.se);
                par.push_back(x.se);
            }
            mm = nd[i].size();
            dfs2(nw[0].se, -1);
            for(auto x : nw){
                G[x.se].clear();
            }
        }
    }
    cout << res << "\n";
    return 0;
}