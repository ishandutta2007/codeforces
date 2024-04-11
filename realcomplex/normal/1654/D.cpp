#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int MOD = 998244353;
int low[N];


struct edge{
    int nex;
    int xi;
    int yi;
};

vector<edge> T[N];

int cnt[N];
int maxi[N];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k /2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

void add(int p, int sign, bool add){
    while(p != 1){
        cnt[low[p]] += sign;
        if(add)maxi[low[p]] = max(maxi[low[p]], -cnt[low[p]]);
        p /= low[p];
    }
}

int sum;

void dfs(int node, int pp, int g){
    int nx;
    sum = (sum + g) % MOD;
    for(auto x : T[node]){
        if(x.nex == pp) continue;
        add(x.xi, +1, false);
        add(x.yi, -1, true);
        nx = (g * 1ll * x.xi) % MOD;
        nx = (nx * 1ll * powr(x.yi, MOD-2)) % MOD;
        dfs(x.nex, node, nx);
        add(x.yi, +1, false);
        add(x.xi, -1, false);
    }
}

void solve(){
    int n;
    cin >> n;
    int u, v, x, y;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        cnt[i] = 0;
        maxi[i] = 0;
    }
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v >> x >> y;
        T[u].push_back({v, y, x});
        T[v].push_back({u, x, y});
    }
    sum = 0;
    dfs(1, -1, 1);
    int go = sum;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j < maxi[i]; j ++ ){
            go = (go * 1ll * i) % MOD;
        }
    }
    cout << go << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    low[1] = 1;
    for(int i = 2; i < N ;i  ++ ){
        if(low[i] == 0){
            for(int j = i; j < N ; j += i){
                if(low[j] == 0) low[j] = i;
            }
        }
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}