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
    int n;
    cin >> n;
    ll prev;
    cin >> prev; int fa = 0;
    range(i, n - 1) {
        ll f;
        cin >> f;
        if (abs(f - prev) >= 2 && !fa) {
            cout << "YES\n";
            cout << i + 1 << ' ' << i + 2 << '\n';
            fa = 1;
        }
        prev = f;
    }
    if (fa) return;
    cout << "NO\n";
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