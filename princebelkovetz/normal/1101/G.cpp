#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int LOG = 31;
int basis[LOG], ans = 0;

void add(int x) {
    for (int i = LOG - 1; i >= 0; --i) {
        if (x & (1ll << i)) {
            if (basis[i]) {
                x ^= basis[i];
            }
            else {
                basis[i] = x;
                ans++;
                return;
            }
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int n, xorSum = 0; cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        xorSum ^= x;
        add(xorSum);
    }
    cout << (xorSum ? ans : -1) << '\n';
}