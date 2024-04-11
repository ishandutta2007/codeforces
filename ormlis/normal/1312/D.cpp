#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
ll md = 998244353;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return (1ll * binpow(a, b - 1) * a) % md;
    ll m = binpow(a, b / 2);
    return (1ll * m * m) % md;
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << 0;
        return;
    }
    vector<ll> fact(max(n, m) + 1, 0), revfact(max(n, m) + 1, 0);
    fact[0] = revfact[0] = 1;
    for (int i = 1; i < (int) fact.size(); ++i) {
        fact[i] = (1ll * fact[i - 1] * i) % md;
        revfact[i] = (1ll * revfact[i-1] * binpow(i, md - 2)) % md;
    }
    auto C = [&](int n, int k) {
        return (1ll * fact[n] * revfact[n-k] % md) * revfact[k] % md;
    };
    int s =  C(m, n - 1);
    int ans = (1ll * C(m, n - 1) * (n - 2)) % md;
    ans = (1ll * ans * binpow(2, n - 3)) % md;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}