#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
int po[20][N];
vector<int> g[N];
vector<int> d(N);
vector<int> prime(N, 1);
vector<vector<int>> add(N);
vector<bool> can(N), used(N);
vector<int> a;
int ans = 0;

int lca(int a, int b){
    if (d[a] < d[b]){
        swap(a, b);
    }
    for (int i = 19; i >= 0; i--){
        if (d[po[i][a]] >= d[b]){
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--){
        if (po[i][a] != po[i][b]){
            a = po[i][a], b = po[i][b];
        }
    }
    return po[0][a];
}

int dist(int a, int b){
    return (d[a] + d[b] - 2 * d[lca(a, b)]);
}

void dfs(int v, int p){
    for (auto to : g[v]){
        if (to != p){
            d[to] = d[v] + 1;
            po[0][to] = v;
            dfs(to, v);
        }
    }
}

void zhfs(int v){
    a.pb(v);
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to] && can[to]){
            zhfs(to);
        }
    }
}

void func(int v){
    a.clear();
    zhfs(v);
    int s = a[0], f = a[0];
    for (int i = 1; i < a.size(); i++){
        if (dist(s, f) < dist(s, a[i])){
            f = a[i];
        }
        if (dist(s, f) < dist(a[i], f)){
            s = a[i];
        }
    }
    ans = max(ans, dist(s, f) + 1);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    prime[0] = prime[1] = 1;
    for (int i = 2; i < N; i++){
        if (!prime[i]) continue;
        for (int j = i * i; j < N; j += i){
            prime[j] = 0;
        }
    }
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        int now = 2;
        while(!prime[a]){
            if (a % now == 0){
                while(a % now == 0) a /= now;
                add[now].pb(i);
            }
            now++;
        }
        if (a >= 2) add[a].pb(i);
    }
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, -1);
    po[0][1] = 1;
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 0; i < N; i++){
        for (auto to : add[i]){
            can[to] = 1;
        }
        for (auto to : add[i]){
            if (!used[to]){
                func(to);
            }
        }
        for (auto to : add[i]){
            used[to] = 0, can[to] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}