#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define NO { cout << "NO\n"; return 0; }
using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        if (n & 1 ^ 1) {
            cout << (n == 2 ? -1 : n / 4) << '\n';
        }
        else {
            cout << (n <= 7 or n == 11 ? -1 : 1 + (n - 9) / 4) << '\n';
        }
    }
    return 0;
}