#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

bool good(vector<vector<int>> a) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            if (a[i][j] > a[i][j + 1]) {
                return 0;
            }
        }
    }
    return 1;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        b = a;
        set<int> st;
        for (int i = 0; i < n; i++) {
            sort(b[i].begin(), b[i].end());
            for (int j = 0; j < m; j++) {
                if (a[i][j] != b[i][j]) {
                    st.insert(j);
                }
            }
        }
        if (st.size() == 0) {
            cout << 1 << ' ' << 1 << endl;
        } else {
            int x = *st.begin(), y = *st.rbegin();
            for (int i = 0; i < n; i++) {
                swap(a[i][x], a[i][y]);
            }
            if (good(a)) {
                cout << x + 1 << ' ' << y + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}