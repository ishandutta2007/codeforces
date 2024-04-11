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
int all(int n) {
    return n * (n - 1) / 2;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(5);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        vector <int> cnt(n + 1);
        for (auto x : a)
            cnt[x]++;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans += all(cnt[i]) * (cnt[i] - 2) / 3;
        }
        for (int i = 0; i <= n - 2; ++i) {
            ans += cnt[i] * cnt[i + 1] * cnt[i + 2];
            ans += all(cnt[i]) * cnt[i + 2];
            ans += cnt[i] * all(cnt[i + 2]);
        }
        for (int i = 0; i <= n - 1; ++i) {
            ans += all(cnt[i]) * cnt[i + 1];
            ans += cnt[i] * all(cnt[i + 1]);
        }
        cout << ans << '\n';

    }
}