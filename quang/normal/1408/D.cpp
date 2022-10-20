#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int n, m;
int a[N], b[N], c[N], d[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }
    vector<pair<int, int>> ls;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = c[j] - a[i] + 1;
            int y = d[j] - b[i] + 1;
            if (x > 0 & y > 0) ls.push_back({x, y});
        }
    }
    sort(ls.begin(), ls.end());
    vector<pair<int, int>> st;
    st.push_back({0, 1e9});
    for (auto u : ls) {
        while (!st.empty() && st.back().second <= u.second) st.pop_back();
        st.push_back(u);
    }
    st.push_back({1e9, 0});
    int res = 1e9;
    for (int i = 0; i + 1 < st.size(); i++) {
        res = min(res, st[i].first + st[i + 1].second);
    }
    cout << res << '\n';
    return 0;
}