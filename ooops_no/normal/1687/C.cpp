#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define ll long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), b(n + 1);
        vector<pair<int,int>> seg(m);
        vector<vector<int>> need(n + 1);
        set<int> zero{0}, st{n + 1};
        deque<int> q;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            st.insert(i);
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> seg[i].first >> seg[i].second;
            seg[i].first--;
            need[seg[i].first].pb(i);
            need[seg[i].second].pb(i);
        }
        for (int i = 1; i <= n; i++) {
            sum += a[i] - b[i];
            if (sum == 0) {
                zero.insert(i);
            }
        }
        for (int i = 0; i < m; i++) {
            if (zero.find(seg[i].first) != zero.end() && zero.find(seg[i].second) != zero.end()) {
                q.pb(i);
            }
        }
        while (q.size() > 0) {
            int ind = q.front();
            q.pop_front();
            int i = seg[ind].first, j = seg[ind].second;
            while (*st.lower_bound(i) < j) {
                int val = *st.lower_bound(i);
                st.erase(val);
                zero.insert(val);
                for (auto i : need[val]) {
                    if (zero.find(seg[i].first) != zero.end() && zero.find(seg[i].second) != zero.end()) {
                        q.pb(i);
                    }
                }
            }
        }
        if (zero.size() == n + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}