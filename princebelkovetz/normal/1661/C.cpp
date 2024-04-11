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

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        int mx = 0;
        for (auto& x : a) {
            cin >> x;
            mx = max(mx, x);
        }
        int l = -1, r = 1e15;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int ones = (m + 1) / 2, twos = m / 2;
            auto check = [&](int to) {
                int curOnes = ones, curTwos = twos;
                for (auto &x : a) {
                    int canTwo = min((to - x) / 2, curTwos);
                    curTwos -= canTwo;
                    curOnes -= (to - x - canTwo * 2);
                }
                return curOnes >= 0;
            };

            if (check(mx) or check(mx + 1)) r = m;
            else l = m;
        }
        cout << r << '\n';
    }

    return 0;
}