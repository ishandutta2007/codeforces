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

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 2e5 + 12;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        map <int, int> cnt;
        for (auto& x : a) cnt[x]++;
        for (int i = 0; i < n - 1; i++) {
            map <int, int> newCnt;
            int lst = -1;
            for (auto& x : cnt) {
                if (x.second > 1) newCnt[0] += x.second - 1;
                if (lst != -1) newCnt[x.first - lst]++;
                lst = x.first;
            }
            cnt.swap(newCnt);
        }
        cout << cnt.begin()->first << '\n';
    }

    return 0;
}