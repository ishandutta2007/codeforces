#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 300002, M = 11;
ll inf = 1e18;
ll a[N], ps[N], mn[M];
ll n, m, k;

ll x(ll l, ll r) {
    r += m;
    return (r - l + m - 1) / m - l / m - r / m;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    rep(i, n) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }
    ll ans = 0;
    for (int i = 1; i < m; i++)
        mn[i] = inf;
    for (int i = 1; i <= n; i++) {
        ll cc = ps[i] - i / m * k;
        rep(j, m) {
            ans = max(ans, cc - mn[j] - x(j, i % m) * k);
        }
        mn[i % m] = min(mn[i % m], cc);
    }
    cout << ans;
}