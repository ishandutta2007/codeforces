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

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 20;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (auto& x : a) {
        char c; cin >> c;
        x = 1ll << (c - 'a');
    }
    int res = a[n - 1] - a[n - 2];
    for (int i = 0; i < n - 2; ++i)
        res -= a[i];
    vector <int> add;
    for (int i = 0; i < n - 2; ++i)
        add.push_back(2 * a[i]);
    sort(add.rbegin(), add.rend());
    int diff = k - res;
    for (auto& x : add) {
        if (x <= diff) diff -= x;
    }
    cout << (diff ? "No" : "Yes") << '\n';

    return 0;
}