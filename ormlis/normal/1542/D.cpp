#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 1e5 + 1;
const int md = 998244353;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> ord;
    range(i, n) {
        char x; cin >> x;
        if (x == '+') {
            a[i].first = 1;
            cin >> a[i].second;
            ord.push_back(i);
        } else {
            a[i].first = -1;
        }
    }
    sort(all(ord), [&] (const int &i, const int &j) {
       return a[i].second < a[j].second;
    });
    vector<bool> was(n);
    int ans = 0;
    for(auto &i : ord) {
        vector<vector<int>> newdp(n + 1, vector<int> (n + 1));
        newdp[0][0] = 1;
        range(j, n) {
            if (j != i) newdp[j + 1] = newdp[j];
            if (a[j].first == 1) {
                if (was[j]) {
                    range(w, n) {
                        newdp[j + 1][w + 1] = add(newdp[j + 1][w + 1], newdp[j][w]);
                    }
                } else {
                    range(w, n + 1) {
                        newdp[j + 1][w] = add(newdp[j + 1][w], newdp[j][w]);
                    }
                }
            } else {
                range(w, n + 1) {
                    if (j > i && w == 0) continue;
                    newdp[j + 1][max(w - 1, 0)] = add(newdp[j + 1][max(w - 1, 0)], newdp[j][w]);
                }
            }
        }
        was[i] = true;
        for(int c = 0; c <= n; ++c) {
            ans = add(ans, mul(a[i].second, newdp[n][c]));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}