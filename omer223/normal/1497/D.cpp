#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;

void solve() {
    int n;
    cin >> n;
    vector<ll> s(n);
    vector<int> tag(n);
    foru(i, 0, n)cin >> tag[i];
    foru(i, 0, n)cin >> s[i];
    vector<ll> dp(n);
    foru(i, 0, n) {
        ford(j, i - 1, 0) {
            ll dpi = dp[i], dpj = dp[j], sd = abs(s[i] - s[j]);
            if (tag[i] == tag[j])continue;
            chkmax(dp[i], dpj + sd);
            chkmax(dp[j], dpi + sd);
        }
    }
    ll ans = 0;
    foru(i, 0, n)chkmax(ans, dp[i]);
    cout << ans << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}