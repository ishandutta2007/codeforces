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
    string s;
    cin >> s;
    ll su = 0;
    int f = 0, f2 = 0;
    for(auto c: s) {
        su += c - '0';
        if (c == '0') {
            f2 += 1;
        }
        if ((c - '0') % 2 == 0) {
            f += 10;
        }
    }
    if (f2 && f >= 20 && su % 3 == 0) {
        cout << "red\n";
    } else {
        cout << "cyan\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests;
    cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}