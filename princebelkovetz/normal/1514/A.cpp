#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int N = 1e2 + 5;
int re[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    while (testcases --> 0) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        bool c = false;
        for (auto& x : a) {
            int l = -1, r = x + 2;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (m * m > x) r = m;
                else l = m;
            }
            if (l * l != x) c = true;
        }
        cout << (c ? "YES\n" : "NO\n");
    }
    return 0;
}