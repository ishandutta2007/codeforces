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
#include <chrono>
#include <unordered_set>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define set unordered_set

using namespace std;
const int root = 212, mod = 998244353, N = 5e5 + 2;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int plus = 0, minus = 0, cur = 0, can = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '+') {
                    plus++;
                    minus += cur & 1;
                    can += cur >> 1;
                    cur = 0;
                }
                else {
                    cur++;
                }
                int curMinus = minus + (cur & 1);
                int curCan = can + (cur >> 1);
                int ok = (2 * curCan - plus + curMinus);
                if (ok % 3 == 0 and ok >= 0) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }



    return 0;
}