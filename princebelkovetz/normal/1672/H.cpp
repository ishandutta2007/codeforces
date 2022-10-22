#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector <int> p00(n + 1), p11(n + 1);
    for (int i = 1; i < n; ++i) {
        p00[i + 1] = p00[i];
        p11[i + 1] = p11[i];
        if (s[i] == s[i - 1] and s[i] == '0') p00[i + 1]++;
        if (s[i] == s[i - 1] and s[i] == '1') p11[i + 1]++;
    }


    // 1001110110 -> 10110110 -> 101010 -> ?
    while (q--) {
        int l, r; cin >> l >> r;
        cout << max(p11[r] - p11[l], p00[r] - p00[l]) + 1 << '\n';
    }

    return 0;
}