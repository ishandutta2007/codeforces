#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> d(N);
vector<int> cnt(N);

void dfs(int v, int p){
    cnt[d[v]]++;
    for (auto to : g[v]){
        if (to != p){
            d[to] = d[v] + 1;
            dfs(to, v);
        }
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        g[a].pb(i);
        g[i].pb(a);
    }
    dfs(1, -1);
    int ans = 0;
    for (int i = 0; i < N; i++){
        ans += cnt[i] % 2;
    }
    cout << ans << endl;
    return 0;
}