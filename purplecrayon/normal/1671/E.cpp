#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int BASE, po[N];
int n;
string s;

int add(int a, int b, int len) {
    return ((long long) a * po[len] + b) % MOD;
}
pair<int, int> dfs(int c, int d) {
    if (c > sz(s)) {
        return {1, 0};
    }
    auto one = dfs(2*c, d+1), two = dfs(2*c+1, d+1);
    if (one.second < two.second) swap(one.second, two.second);

    int ans = ((long long) one.first * two.first * 2) % MOD;
    if (one.second == two.second) {
        ans = ((long long) one.first * two.first) % MOD;
        assert(one.first == two.first);
    }

    int sz = (1 << (n - d)) - 1;
    int sub = add(one.second, two.second, sz);
    int h = add(s[c-1] - 'A' + 1, sub, 2 * sz);
    return {ans, h};
}

void solve() {
    cin >> n >> s;
    BASE = rnd(31, 1e8);
    po[0] = 1;
    for (int i = 1; i < N; i++) po[i] = (long long) po[i-1] * BASE % MOD;

    int ans = dfs(1, 0).first;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}