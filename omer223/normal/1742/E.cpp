#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), ans(q);
    vector<pll> k(q);
    foru(i, 0, n)cin >> a[i];
    foru(i, 0, q)cin >> k[i].ff, k[i].ss = i;
    sort(k.begin(), k.end());
    int kidx = 0, aidx = 0;
    ll crs = 0;
    while (kidx < q) {
        while (aidx < n && a[aidx] <= k[kidx].ff) {
            crs += a[aidx++];
        }
        ans[k[kidx++].ss] = crs;
    }
    foru(i, 0, q)cout << ans[i] << ' ';
    cout << '\n';
    
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}