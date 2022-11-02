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
    int n;
    cin >> n;
    vector<ll> a(n);
    foru(i, 0, n)cin >> a[i];
    ll op = (1LL << 31) - 1;
    ll crmsk = 0;
    vector<ll> ret;
    vector<bool> used(n, false);
    foru(iter, 0, n) {
        ll mxadd = 0;
        int mxidx = -1;
        foru(i, 0, n) {
            if (used[i])continue;
            ll cand = ((crmsk ^ op) & a[i]);
            if (cand > mxadd) {
                mxadd = cand;
                mxidx = i;
            }
        }
        if (mxidx != -1) {
            ret.push_back(a[mxidx]);
            used[mxidx] = 1;
            crmsk |= (a[mxidx]);
        }
        else break;
    }
    foru(i, 0, n) {
        if (!used[i])ret.push_back(a[i]);
    }
    for (ll x : ret)cout << x << ' ';
    cout << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}