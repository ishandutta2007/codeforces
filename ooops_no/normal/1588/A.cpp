#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back

mt19937 rnd(51);

const int N = 110;
vector<int> g[N];
vector<bool> used(N);
vector<int> mt(N, -1);

bool dfs(int v){
    if (used[v]) return 0;
    used[v] = 1;
    for (auto to : g[v]){
        if (mt[to] == -1){
            mt[to] = v;
            return 1;
        }
    }
    for (auto to : g[v]){
        if (dfs(mt[to])){
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        for (int i = 0; i < N; i++){
            g[i].clear();
            mt[i] = -1;
        }
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[i] + 1 == b[j] || a[i] == b[j]){
                    g[i].pb(j);
                }
            }
        }
        for (int i = 0; i < n; i++){
            fill(used.begin(), used.end(), 0);
            dfs(i);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) if (mt[i] != -1) cnt++;
        cout << (cnt == n ? "YES" : "NO") << endl;
    }
    return 0;
}