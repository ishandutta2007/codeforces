#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int N = 3e5 + 10;
vector<set<int>> g(N);
set<int> all;

void bfs(int v){
    deque<int> q{v};
    all.erase(v);
    while(q.size() > 0){
        int u = q.front();
        q.pop_front();
        vector<int> del;
        for (auto to : all){
            if (g[u].find(to) == g[u].end()){
                q.pb(to);
                del.pb(to);
            }
        }
        for (auto to : del) all.erase(to);
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    for (int i = 0; i < n; i++) all.insert(i);
    bfs(0);
    for (int i = 0; i < n; i++){
        if (all.find(i) != all.end()){
            cout << "impossible";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) all.insert(i);
    all.erase(0);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (all.find(i) != all.end()){
            bfs(i);
            ans++;
        }
    }
    if (ans <= k && k <= (n - 1) - (int)(g[0].size())){
        cout << "possible" << endl;
    }
    else{
        cout << "impossible" << endl;
    }
    return 0;
}