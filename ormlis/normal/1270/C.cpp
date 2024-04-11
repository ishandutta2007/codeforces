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

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

void solve() {
    int n; cin >> n;
    ll su = 0, x = 0;
    range(i, n) {
        ll el; cin >> el;
        su += el; x ^= el;
    }
    cout << 2 << '\n';
    cout << x << ' ';
    su += x;
    cout << su << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}