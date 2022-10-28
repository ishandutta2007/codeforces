#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void push(vector<pair<ll, ll>>& v, ll x, ll cnt) {
    if (!sz(v) || v.back().first != x) v.emplace_back((long long) x, cnt);
    else {
        v.back().second += cnt;
    }

}
auto reduce(vector<int> a, int m) {
    vector<pair<ll, ll>> v;
    for (int x : a) {
        int use = x;
        ll cnt = 1;
        while (use % m == 0) {
            use /= m;
            cnt *= m;
        }
        push(v, use, cnt);
    }
    return v;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int k; cin >> k;
    vector<int> b(k); for (auto& x : b) cin >> x;
    auto v = reduce(a, m);
    cout << (reduce(a, m) == reduce(b, m) ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}