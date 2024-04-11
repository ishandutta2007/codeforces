#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int K = 102;
const ll MOD = (ll)1e9 + 7;

vector<int> T[N];

int sz = 0;

bool vis[N];

void dfs(int u, int par){
    if(vis[u]) return;
    vis[u] = true;
    sz ++ ;
    for(auto x : T[u]){
        dfs(x,u);
    }
}

ll powr(ll n, ll k){
    if(k == 0) return 1;
    ll p = powr(n,k/2);
    p = (p * p) % MOD;
    if(k&1) p = (p * n) % MOD;
    return p;
}

int main(){
    fastIO;
    int n,k;
    cin >> n >> k;
    int u, v, r;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v >> r;
        if(r == 0){
            T[u].push_back(v);
            T[v].push_back(u);
        }
    }
    ll answ = powr(n,k);
    for(int i = 1; i <= n; i ++ ){
        sz = 0;
        dfs(i,-1);
        answ -= powr(sz,k);
        answ += MOD;
        answ %= MOD;
    }
    cout << answ;
    return 0;
}