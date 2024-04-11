#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e18;
const ll mod = 998244353;

void run() {
    string f = "10";
    f.reserve(3e6);
    vector<int> fib{1, 1};
    while (f.size() < 2e6 + 3) {
        for (int i = 0; i < fib.back(); ++i)
            f.push_back(f[i]);

        fib.push_back(fib.back() + fib.end()[-2]);
    }
    fib.push_back(fib.back() + fib.end()[-2]);

    int n; cin >> n;
    ll sum = 1;
    int sz = 0;
    vector<pair<int, ll>> pot, npot;

    ll res = 1;
    for (int it = 0; it < n; ++it) {
        string s; cin >> s;

        for (int i = 0; i < s.size(); ++i, ++sz) {
            ll bad = 0;
            pot.emplace_back(sz, res);
            for (auto [a, b] : pot) {
                if (sz - a < f.size() && f[sz - a] == s[i]) {
                    npot.emplace_back(a, b);
                    if (*lower_bound(all(fib), sz - a + 1) == sz - a + 1) {
                        bad += b;
                    }
                } else if (sz == a) {
                    bad += b;
                }
            }

            swap(pot, npot);
            npot.clear();

            res = ((sum - bad) % mod + mod) % mod;
            sum += res;

            // cout << "res " << res << '\n';
            /*for (auto [a, b] : pot) {
                cout << a << " " << b << '\n';
            }
            cout << '\n';*/
        }
        cout << res << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}