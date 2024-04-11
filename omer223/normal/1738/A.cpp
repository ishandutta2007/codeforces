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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

void solve() {
    int n;
    cin >> n;
    vector<int> v[2];
    vector<int> a(n);
    foru(i, 0, n) {
        cin >> a[i];
    }
    ll sum = 0;
    foru(i, 0, n) {
        int x;
        cin >> x;
        v[a[i]].push_back(x);
    }
    foru(i, 0, 2) {
        for (ll x : v[i]) {
            sum += x;
            //totmn = min(totmn, x);
        }
    }
    foru(j, 0, 2)sort(v[j].rbegin(), v[j].rend());
    int mn = min(v[0].size(), v[1].size());
    if (2 * mn == n) {
        ll totmn = 1e15;
        foru(i, 0, 2) {
            for (ll x : v[i]) {
                totmn = min(totmn, x);
            }
        }
        cout << 2*(sum - totmn)+totmn << '\n';
    }
    else {
        foru(j, 0, mn)sum += (v[0][j] + v[1][j]);
        cout << sum << '\n';
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}