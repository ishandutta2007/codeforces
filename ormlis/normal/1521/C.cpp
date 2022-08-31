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
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> ord(n);
    iota(all(ord), 0);
    shuffle(all(ord), rng);
    auto query = [&](int t, int i, int j, int x) {
        cout << "? " << t << ' ' << ord[i] + 1 << ' ' << ord[j] + 1 << ' ' << x << endl;
        int r;
        cin >> r;
        if (r == -1) exit(0);
        return r;
    };
    auto fnd = [&](int i, int j) {
        int l = 0;
        int r = n;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (query(1, j, i, mid) != mid + 1) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    };
    vector<int> ans(n);
    ans[0] = fnd(0, 1);
    int mn = 0;
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        if (rng() % 2) {
            if (ans[mn] != n) {
                int r = query(1, mn, i, n - 1);
                if (r != ans[mn]) {
                    ans[i] = r;
                    if (r < ans[mn]) {
                        mn = i;
                    }
                    if (r > ans[mx]) {
                        mx = i;
                    }
                    continue;
                }
            }
        }
        if (ans[mx] != 1) {
            int r = query(2, i, mx, 1);
            if (r != ans[mx]) {
                ans[i] = r;
                if (r < ans[mn]) {
                    mn = i;
                }
                if (r > ans[mx]) {
                    mx = i;
                }
                continue;
            }
        }
        if (ans[mn] != n) {
            int r = query(1, mn, i, n - 1);
            if (r != ans[mn]) {
                ans[i] = r;
                if (r < ans[mn]) {
                    mn = i;
                }
                if (r > ans[mx]) {
                    mx = i;
                }
                continue;
            }
        }
        assert(0);
    }
    cout << "! ";
    vector<int> tans(n);
    range(i, n) tans[ord[i]] = ans[i];
    range(i, n) {
        cout << tans[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}