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
    int n; cin >> n;
    vector<int> a(n);
    vector<array<ll, 2>> mn(n, {n, n}), pre(n+1, {0, 0});

    for (auto &i : a)
        cin >> i;

    auto chmin = [](array<ll, 2>& a, ll val) {
        if (a[0] > val)
            a[1] = a[0], a[0] = val;
        else if (a[1] > val)
            a[1] = val;
    };

    for (int i = n-1; i >= 0; --i)
        if (i - a[i] >= 0)
            chmin(mn[i - a[i]], i);

    for (int i = n-2; i >= 0; --i) {
        chmin(mn[i], mn[i+1][0]);
        chmin(mn[i], mn[i+1][1]);
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j)
        pre[i+1][j] = pre[i][j] + mn[i][j];

    ll res = 0;
    for (int i = 0; i < n; ++i)
        res += mn[i][0];
    cout << res - (ll)n*(n-1) / 2 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}