#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
set<int> g[N];
vector<int> d(N), was(N);
set<pair<int,int>> st;

void dfs(int v, int p) {
    for (auto to : g[v]) {
        if (to != p) {
            d[to] = d[v] + 1;
            dfs(to, v);
        }
    }
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
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p == 0) continue;
        p--;
        g[p].insert(i);
        g[i].insert(p);
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() >= 2) {
            r = i;
        }
    }
    dfs(r, -1);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        st.insert({-d[i], i});
    }
    while (st.size() > 0) {
        int v = st.begin()->second;
        st.erase(st.begin());
        if (g[v].size() & 1 || was[v]) {
            continue;
        }
        ans.pb(v);
        was[v] = 1;
        vector<int> arr;
        for (auto to : g[v]) arr.pb(to);
        for (auto to : arr) {
            g[v].erase(to);
            g[to].erase(v);
            st.insert({-d[to], to});
        }
    }
    if (ans.size() != n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto to : ans) {
        cout << to + 1 << endl;
    }
    return 0;
}