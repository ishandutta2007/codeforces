#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;
typedef long double ld;

using namespace std;

const int maxN = 1e7 + 5;
const int INFi = 2e9;
const ll INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    range(i, n) range(j, m) cin >> a[i][j];
    function<void(vector<int>, bool)> check = [&] (vector<int> v, bool tried = false) {
        range(i, n) {
            int cnt = 0;
            range(j, m) cnt += (v[j] != a[i][j]);
            if (cnt > 3) return;
            if (cnt > 2) {
                if (tried) return;
                range(j, m) {
                    if (v[j] != a[i][j]) {
                        auto w = v;
                        w[j] = a[i][j];
                        check(w, true);
                    }
                }
                return;
            }
        }
        cout << "Yes\n";
        range(i, m) cout << v[i] << ' ';
        exit(0);
    };
    check(a[0], false);

    range(i, n) {
        vector<int> kek;
        range(j, m) {
            if (a[i][j] != a[0][j]) {
                kek.push_back(j);
            }
        }
        if (kek.size() > 4) {
            cout << "No\n";
            return;
        }
        if (kek.size() <= 2) continue;
        for(int &x : kek) {
            for(int &y : kek) {
                auto c = a[0];
                c[x] = a[i][x];
                c[y] = a[i][y];
                check(c, false);
            }
        }
        break;
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}