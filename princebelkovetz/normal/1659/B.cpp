#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <cassert>
#include <numeric>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, k, lft; cin >> n >> k;
        lft = k;
        string s; cin >> s;
        vector <int> ans(n);
        for (int i = 0; i < n; ++i) {
            if ((s[i] == '0') ^ (k & 1)) 
                if (lft) ans[i] = 1, lft--;
        }
        ans.back() += lft;
        string res = s;
        for (int i = 0; i < n; ++i) {
            if ((k - ans[i]) & 1) res[i] = (s[i] == '1' ? '0' : '1');
        }
        cout << res << '\n';
        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
    }


    return 0;
}