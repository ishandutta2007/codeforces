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
#include <bitset>

#define ll long long
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    vector<ll> pref(n + 1, 0);
    vector<ll> dp(2, 0);
    ll ans = 0;
    range(i, n) {
        ll ai; cin >> ai;
        bitset<64> bits(ai);
        a[i] = bits.count();
        pref[i + 1] = (pref[i] + a[i]) & 1;
    }
    for(int i = 1; i <= n; ++i) {
        ans += dp[pref[i]];
        dp[pref[i - 1]]++;
    }
    range(r, n) {
        ll maxx = a[r]; ll su = a[r];
        for(int l = r - 1; l >= max(0, r - 65); --l) {
            maxx = max(maxx, a[l]);
            su += a[l];
            if (!(su & 1) && maxx * 2 > su) ans--;
            if (su > 128) break;
        }
    }
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