#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;
ll MOD = 1e9 + 7;
ll sub(ll a, ll b) {
    if (a - b < 0) return a - b + MOD;
    return a - b;
}

ll add(ll a, ll b) {
    if (a + b >= MOD) return a + b - MOD;
    return a + b;
}

ll mul(ll a, ll b) {
    return a * b % MOD;
}


void solve() {
    ll r, c;
    cin >> r >> c;
    if (c == r && r == 1) {
        cout << 0;
        return;
    }
    if (c == 1) {
        range(i, r) {
            cout << i + 2 << '\n';
        }
        return;
    }
    if (r == 1) {
        range(i, c) {
            cout << i + 2 << ' ';
        }
        cout << '\n';
        return;
    }
    vector<vector<ll>> ans(r, vector<ll> (c));
    for(ll i = 0; i < r; ++i) {
        for(ll j = 0; j < c; ++j) {
            cout << (i + 1) * (r + j + 1) / __gcd(i + 1, r + j + 1) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}