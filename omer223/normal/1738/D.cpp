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
    vector<int> b(n+1);
    bool n1 = 0;
    foru(i, 0, n)cin >> b[i+1], n1 |= (b[i+1] == n + 1);
    vector<vector<int>> locs(n + 2);
    for (int i = 1; i <= n; i++)locs[b[i]].push_back(i);
    int curcand = (n1?n+1:0), nxtcand = -1;
    vector<int> a;
    while (curcand != -1) {
        for (int x : locs[curcand]) {
            if (!locs[x].empty()) {
                nxtcand = x;
                break;
            }
        }
        for (int x : locs[curcand]) {
            if (x != nxtcand)a.push_back(x);
        }
        if (nxtcand != -1)a.push_back(nxtcand);
        curcand = nxtcand;
        nxtcand = -1;
    }
    int mnr = 1e9, mxl = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] > i) {
            mxl = i;
        }
    }
    cout << mxl << '\n';
    for (int x : a)cout << x << ' ';
    cout << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}