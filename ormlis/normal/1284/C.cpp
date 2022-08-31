#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <cmath>
#include <unordered_map>
#include <array>

#define ll long long
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

const ll INF = 1e18;
const int maxN = 200001;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> fact(n + 1);
    ll cur = 1;
    fact[0] = 1;
    for(ll i = 1; i <= n; ++i) {
        cur = (cur * i) % m;
        fact[i] = cur;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ans = (ans + ((n - i + 1) * fact[i] % m * (n - i + 1) % m * fact[n - i] % m)) % m;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    //cin >> tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}