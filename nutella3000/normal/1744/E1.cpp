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
    ll a, b, c, d; cin >> a >> b >> c >> d;
    
    map<ll, int> del;
    {   
        ll _a = a, _b = b;
        for (ll i = 2; i * i <= _a; ++i) {
            while (_a % i == 0) {
                ++del[i];
                _a /= i;
            }
        }
        for (ll i = 2; i * i <= _b; ++i) {
            while (_b % i == 0) {
                ++del[i];
                _b /= i;
            }
        }
        if (_a != 1) ++del[_a];
        if (_b != 1) ++del[_b];
    }

    vector<ll> all{1}, nall;
    for (auto [num, cnt] : del) {
        for (auto i : all) {
            for (ll j = 1, val = num; j <= cnt; ++j, val *= num) {
                nall.push_back(i * val);
            }
        }
        all.insert(all.end(), all(nall));
        nall.clear();
    }
    for (ll x : all) {
        ll y = a*b/x;
        x *= a / x + 1;
        y *= b / y + 1;

        if (x <= c && y <= d) {
            cout << x << " " << y << '\n';
            return;
        }
    }
    cout << "-1 -1\n";
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}