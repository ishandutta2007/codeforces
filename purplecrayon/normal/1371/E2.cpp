#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;
const ll INF = 1e18+10;

void solve() {
    int n, p; cin >> n >> p;
    vector<ll> a(n); for (auto& x : a) cin >> x;

    auto get_mult = [&](ll x) -> vector<int> {
        vector<int> b(n);
        for (ll c : a) {
            if (c - x >= n) return {0};
            b[max(0LL, c - x)]++;
        }
        int sum = 0;
        vector<int> mult;
        for (int i = 0; i < n; i++) {
            sum += b[i];
            mult.push_back(sum);
            sum--;
        }
        return mult;
    };
    auto non_zero = [&](ll x) {
        auto c = get_mult(x);
        for (auto& v : c) if (v == 0) return false;
        return true;
    };
    auto div_p = [&](ll x) {
        auto c = get_mult(x);
        for (auto& v : c) if (v % p == 0) return true;
        return false;
    };
    auto find_first = [&](ll lo, ll hi, auto f) {
        ll mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            if (f(mid)) hi = mid;
            else lo = mid;
            mid = (lo + hi) / 2;
        } 
        return hi;
    };

    ll one = find_first(0, INF, non_zero);
    ll two = find_first(one - 1, INF, div_p);

    cout << two - one << '\n';
    for (ll i = one; i < two; i++) cout << i << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}