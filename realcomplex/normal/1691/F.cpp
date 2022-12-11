#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int MOD = (int)1e9 + 7;

int fac[N];
int inv[N];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k / 2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

int mult(int x, int y){
    return (x * 1ll * y) % MOD;
}

int pick(int n, int k){
    if(k < 0 || n < 0 || k > n) return 0;
    return mult(fac[n], mult(inv[k], inv[n-k]));
}

vector<int> T[N];

int n, k;
int sub[N];
int only[N];
int res = 0;


void add(int &x, int y){
    x += y;
    if(x < 0) x += MOD;
    else if(x >= MOD)x -= MOD;
}

int cummin = 0;

void dfs(int u, int pa){
    sub[u]=1;
    only[u]=0;
    for(auto x : T[u]){
        if(x == pa) continue;
        dfs(x, u);
        sub[u] += sub[x];
    }
    add(only[u], pick(sub[u], k));
    for(auto x : T[u]){
        if(x == pa) continue;
        add(only[u], -pick(sub[x], k));
    }
    add(cummin, mult(only[u], sub[u]));
}

void change_root(int node, int x){
    add(cummin, -mult(sub[node], only[node]));
    add(cummin, -mult(sub[x], only[x]));

    add(only[node], -pick(sub[node], k));
    add(only[node], +pick(sub[x], k));
    add(only[x], -pick(sub[x], k));

    add(sub[node], -sub[x]);
    add(sub[x], sub[node]);

    add(only[node], +pick(sub[node], k));
    add(only[x], +pick(sub[x], k));
    add(only[x], -pick(sub[node], k));


    add(cummin, +mult(sub[node], only[node]));
    add(cummin, +mult(sub[x], only[x]));
}

void reroot(int node, int pa){
    add(res, cummin);
    for(auto x : T[node]){
        if(x == pa) continue;
        change_root(node, x);
        reroot(x, node);
        change_root(x, node);
    }
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= n; i ++ ){
        fac[i] = (fac[i - 1] * 1ll * i) % MOD;
        inv[i] = powr(fac[i], MOD - 2);
    }
    dfs(1, -1);
    reroot(1, -1);
    cout << res << "\n";
    return 0;
}