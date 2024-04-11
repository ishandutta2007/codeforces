#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N];
vector<int> ind(N);
bool f = 0;
int n, k;

vector<int> bfs(vector<int> a){
    vector<int> d(n, 1e18);
    deque<int> q;
    for (auto to : a){
        d[to] = 0;
        q.pb(to);
    }
    while(q.size() > 0){
        int v = q.front();
        q.pop_front();
        for (auto to : g[v]){
            if (d[to] == 1e18){
                d[to] = d[v] + 1;
                q.pb(to);
            }
        }
    }
    return d;
}

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        g[i].clear();
    }
    vector<int> x(k);
    for (int i = 0; i < k; i++){
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> d = bfs(vector<int>{0}), dd = bfs(x);
    bool f = 0;
    for (int i = 1; i < n; i++){
        if (g[i].size() == 1 && d[i] < dd[i]){
            f = 1;
        }
    }
    cout << (f ? "YES" : "NO") << endl;
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
        solve();
    }
    return 0;
}