#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

int n, m;
vector<vector<int>> a;
vector<pair<int,int>> d{{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {0, 0}};

bool is_bad(int i, int j) {
    if (a[i][j] == 1) return 0;
    if (i - 1 >= 0 && a[i - 1][j] < a[i][j]) {
        return 0;
    }
    if (i + 1 < n && a[i + 1][j] < a[i][j]) {
        return 0;
    }
    if (j - 1 >= 0 && a[i][j - 1] < a[i][j]) {
        return 0;
    }
    if (j + 1 < m && a[i][j + 1] < a[i][j]) {
        return 0;
    }
    return 1;
}

bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int,int>> cell;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_bad(i, j)) {
                cell.pb({i, j});
            }
        }
    }
    if (cell.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    set<pair<int,int>> u;
    for (auto [i, j] : d) {
        if (check(cell[0].first + i, cell[0].second + j)) {
            u.insert({cell[0].first + i, cell[0].second + j});
        }
    }
    int cnt = cell.size(), ans = 0;
    for (auto [i, j] : u) {
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < m; j1++) {
                set<pair<int,int>> st;
                for (auto [f, s] : d) {
                    if (check(i + f, j + s)) {
                        st.insert({i + f, j + s});
                    }
                    if (check(i1 + f, j1 + s)) {
                        st.insert({i1 + f, j1 + s});
                    }
                }
                int new_cnt = cnt;
                for (auto to : st) {
                    new_cnt -= is_bad(to.first, to.second);
                }
                swap(a[i][j], a[i1][j1]);
                for (auto to : st) {
                    new_cnt += is_bad(to.first, to.second);
                }
                if (new_cnt == 0) {
                    ans++;
                }
                swap(a[i][j], a[i1][j1]);
            }
        }
    }
    int del = 0;
    for (auto [i, j] : u) {
        for (auto [i1, j1] : u) {
            set<pair<int,int>> st;
            for (int f = -1; f <= 1; f++) {
                for (int s = -1; s <= 1; s++) {
                    if (check(i + f, j + s)) {
                        st.insert({i + f, j + s});
                    }
                    if (check(i1 + f, j1 + s)) {
                        st.insert({i1 + f, j1 + s});
                    }
                }
            }
            int new_cnt = cnt;
            for (auto to : st) {
                new_cnt -= is_bad(to.first, to.second);
            }
            swap(a[i][j], a[i1][j1]);
            for (auto to : st) {
                new_cnt += is_bad(to.first, to.second);
            }
            if (new_cnt == 0) {
                del++;
            }
            swap(a[i][j], a[i1][j1]);
        }
    }
    if (ans == 0) {
        cout << 2 << endl;
    } else {
        cout << 1 << ' ' << ans - del / 2 << endl;
    }
    return 0;
}