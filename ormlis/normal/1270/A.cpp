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
    int n, k1, k2; cin >> n >> k1 >> k2;
    int flag = 0;
    int f;
    range(i, k1) {
        cin >> f;
        if (f == n) flag = 1;
    }
    range(i, k2) {
        cin >> f;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}