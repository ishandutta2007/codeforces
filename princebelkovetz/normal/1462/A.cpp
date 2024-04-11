#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <queue>
// made by @princebelkovetz //
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(5);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        int l = 0, r = n - 1;
        vector <int> ans;
        int cur = 0;
        while (l <= r) {
            if (cur % 2 == 0) {
                ans.push_back(a[l++]);
            }
            else {
                ans.push_back(a[r--]);
            }
            cur++;
        }
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}