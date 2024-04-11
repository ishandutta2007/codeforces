#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 4e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    range(i, n) range(j, m) {
            char x;
            cin >> x;
            if (x == '1') a[i][j] = 1;
        }
    vector<pair<int, int>> q;
    auto solve3 = [&](int i, int j) {
        for (int e = i; e <= i + 1; ++e) {
            for (int f = j; f <= j + 1; ++f) {
                if (a[e][f]) {
                    q.emplace_back(e, f);
                    a[e][f] ^= 1;
                }
            }
        }
    };

    auto solve2 = [&](int i, int j) {
        bool finded = false;
        for (int e = i; e <= i + 1; ++e) {
            for (int f = j; f <= j + 1; ++f) {
                if (a[e][f]) {
                    if (finded) continue;
                    finded = true;
                    q.emplace_back(e, f);
                    a[e][f] ^= 1;
                    continue;
                }
                q.emplace_back(e, f);
                a[e][f] ^= 1;
            }
        }
        solve3(i, j);
    };

    auto solve1 = [&](int i, int j) {
        int uz = 0;
        for (int e = i; e <= i + 1; ++e) {
            for (int f = j; f <= j + 1; ++f) {
                if (a[e][f]) {
                    q.emplace_back(e, f);
                    a[e][f] ^= 1;
                    continue;
                }
                if (uz == 2) continue;
                q.emplace_back(e, f);
                a[e][f] ^= 1;
                uz++;
            }
        }
        solve2(i, j);
    };

    auto solve4 = [&](int i, int j) {
        q.emplace_back(i, j);
        q.emplace_back(i + 1, j);
        q.emplace_back(i, j + 1);
        a[i][j] = a[i + 1][j] = a[i][j + 1] = 0;
        solve1(i, j);
    };

    auto solve = [&](int i, int j) {
        int cnt = 0;
        for (int e = i; e <= i + 1; ++e) {
            for (int f = j; f <= j + 1; ++f) {
                if (a[e][f]) cnt++;
            }
        }
        if (cnt == 1) solve1(i, j);
        if (cnt == 2) solve2(i, j);
        if (cnt == 3) solve3(i, j);
        if (cnt == 4) solve4(i, j);
    };
    auto solve23 = [&](int i, int j) {
        int c = 0;
        if (a[i][j]) {
            q.emplace_back(i, j);
            a[i][j] ^= 1;
            c++;
        }
        if (a[i + 1][j]) {
            q.emplace_back(i + 1, j);
            a[i + 1][j] ^= 1;
            c++;
        }
        if (c == 0) {
            solve(i, j + 1);
        } else {
            q.emplace_back(i, j + 1);
            a[i][j + 1] ^= 1;
            if (c == 1) {
                q.emplace_back(i + 1, j + 1);
                a[i + 1][j + 1] ^= 1;
            }
            solve(i, j + 1);
        }
    };

    auto solve32 = [&](int i, int j) {
        int c = 0;
        if (a[i][j]) {
            q.emplace_back(i, j);
            a[i][j] ^= 1;
            c++;
        }
        if (a[i][j + 1]) {
            q.emplace_back(i, j + 1);
            a[i][j + 1] ^= 1;
            c++;
        }
        if (c == 0) {
            solve(i + 1, j);
        } else {
            q.emplace_back(i + 1, j);
            a[i + 1][j] ^= 1;
            if (c == 1) {
                q.emplace_back(i + 1, j + 1);
                a[i + 1][j + 1] ^= 1;
            }
            solve(i + 1, j);
        }
    };
    if (n % 2 == 0 && m % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
                solve(i, j);
            }
        }
    } else if (n % 2 == 0 && m % 2 == 1) {
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j + 3 < m; j += 2) {
                solve(i, j);
            }
        }
        for (int i = 0; i < n; i += 2) {
            solve23(i, m - 3);
        }
    } else if (n % 2 == 1 && m % 2 == 0) {
        for (int i = 0; i + 3 < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
                solve(i, j);
            }
        }
        for (int i = 0; i < m; i += 2) {
            solve32(n - 3, i);
        }
    } else {
        for (int i = 0; i + 3 < n; i += 2) {
            for (int j = 0; j + 3 < m; j += 2) {
                solve(i, j);
            }
        }
        for (int i = 0; i + 3 < m; i += 2) {
            solve32(n - 3, i);
        }
        for (int i = 0; i + 3 < n; i += 2) {
            solve23(i, m - 3);
        }
        solve23(n - 3, m - 3);
        solve23(n - 2, m - 3);
    }
    cout << q.size() / 3 << '\n';
    for (int i = 0; i < q.size(); i += 3) {
        for (int j = i; j < i + 3; ++j) {
            cout << q[j].first + 1 << " " << q[j].second + 1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}