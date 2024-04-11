#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2006;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int a, b; int q;
    cin >> a >> b >> q;
    vector<int> c(a * b);
    c[0] = 0;
    for(int i = 1; i < a * b; ++i) {
        c[i] += c[i-1];
        if ((i % a) % b != (i % b) % a) c[i]++;
    }

    auto get = [&] (ll x) {
        return c[x % (1ll * a * b)] + x / (1ll * a * b) * c.back();
    };

    range(i, q) {
        ll l, r; cin >> l >> r;
        cout << get(r) - get(l-1) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}