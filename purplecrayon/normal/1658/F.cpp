#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    int cnt[2] = {};
    for (auto c : s) cnt[c - '0']++;
    if (n % std::gcd(cnt[0], cnt[1]) || m % (n / std::gcd(cnt[0], cnt[1]))) {
        cout << -1 << '\n';
        return;
    }

    auto good = [&](int x) -> bool {
        // x / m == cnt[1] / n
        // x * n == cnt[1] * m
        return (long long) x * n == (long long) cnt[1] * m;
    };

    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        ps[i] = s[i] - '0';
        if (i) ps[i] += ps[i-1];
    }
    auto sum = [&](int l, int r) {
        return ps[r] - (l ? ps[l-1] : 0);
    };

    for (int i = 0; i + m <= n; i++) {
        if (good(sum(i, i + m - 1))) {
            cout << 1 << '\n' << i+1 << ' ' << i+m << '\n';
            return;
        }
    }
    for (int i = 0; i < m-1; i++) {
        int cnt = m - (i + 1);
        if (good(sum(0, i) + sum(n - cnt, n - 1))) {
            cout << 2 << '\n' << 0+1 << ' ' << i+1 << '\n' << n-cnt+1 << ' ' << n << '\n';
            return;
        }
    }
    assert(false);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}