#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int INF = 1e9, N = 2e5 + 10;
vector<int> g[N];

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int,int>> st;
    vector<int> d(n, INF), sz(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[b].pb(a);
        sz[a]++;
    }
    d[n - 1] = 0;
    st.insert({0, n - 1});
    while (st.size() > 0) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for (auto to : g[v]) {
            sz[to]--;
            if (d[v] + sz[to] + 1 < d[to]) {
                st.erase({d[to], to});
                d[to] = d[v] + sz[to] + 1;
                st.insert({d[to], to});
            }
        }
    }
    cout << d[0] << endl;
    return 0;
}