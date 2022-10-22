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
const int root = 212, mod = 1e9 + 7, B = 60, N = 1e3 + 15;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, c, q; cin >> n >> c >> q;
        string s; cin >> s;
        vector <int> lens = { n };
        vector <int> qs = {};
        for (int i = 0, l, r; i < c; ++i) {
            cin >> l >> r;
            r--, l--;
            lens.push_back(lens.back() + r - l + 1);
            qs.push_back(l);
        }
        for (int i = 0; i < q; ++i) {
            int k; cin >> k;
            --k;
            while (k >= n) {
                for (int i = c - 1; i >= 0; i--) {
                    if (lens[i + 1] > k and lens[i] <= k) {
                        k = k - lens[i] + qs[i];
                        break;
                    }
                }
            }
            cout << s[k] << '\n';
        }

    }
    

    return 0;
}