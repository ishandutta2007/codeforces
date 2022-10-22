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
        int n; cin >> n;
        vector <int> a(n), dCnt(10);
        for (auto& x : a) cin >> x, dCnt[x % 10]++;
        bool ans = false;
        for (int i = 0; i < 10; i++) {
            if (!dCnt[i]) continue;
            dCnt[i]--;
            for (int j = 0; j < 10; j++) {
                if (!dCnt[j]) continue;
                dCnt[j]--;
                for (int k = 0; k < 10; k++) {
                    if (!dCnt[k]) continue;
                    if ((i + j + k) % 10 == 3) ans = true;
                }
                dCnt[j]++;
            }
            dCnt[i]++;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}