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
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        bool ok = true;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.size(); ++i) {
            cnt1 += (s[i] == 'A');
            cnt2 += (s[i] == 'B');
            if (s[i] == 'B' and cnt1 < cnt2) ok = false;
        }
        cout << (ok and s[0] == 'A' and s.back() == 'B' ? "YES" : "NO") << '\n';
    }
    return 0;
}