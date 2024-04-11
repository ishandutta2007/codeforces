#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, k; cin >> n >> k;
        k = (n + k - 1) / k * k;
        cout << (k + n - 1) / n << '\n';
    }
    return 0;
}