#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 2e5 + 100;

const ll inf = 1e18 + 100;

int n;

int e[maxn];

const int mod = 1e9 + 7;

ll bpow(ll a, ll b){
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    ll x = bpow(a, b / 2);
    x = (x * x) % mod;
    if (b % 2)
        x = (x * a) % mod;
    return x;
}

ll q[maxn], sz;

ll d[maxn];

bool vis[maxn];

void dfs(int v){
    vis[v] = 1;
    int u = e[v];
    if (d[u] == 0)
        d[u] = d[v] + 1, dfs(u);
    else
    if (!vis[u]){
        vis[v] = 0;
        return;
    }
    else{
        q[sz] = d[v] - d[u] + 1, sz++;
        vis[v] = 0;
        return;
    }
    vis[v] = 0;
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> e[i], e[i]--;
    for (int i = 0; i < n; i++)
        if (d[i] == 0)
            d[i] = 1, dfs(i);
    ll answer = 1;
    ll sum = 0;
    for (int i = 0; i < sz; i++)
        answer = (answer * (bpow(2, q[i]) - 2 + mod)) % mod, sum += q[i];
    sum = n - sum;
    answer = (answer * bpow(2, sum)) %  mod;
    cout << answer;
}