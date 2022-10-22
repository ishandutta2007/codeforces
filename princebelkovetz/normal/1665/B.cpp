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
        int mx = 0;
        map <int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
            mx = max(mx, cnt[x]);
        }
        int ans = 0;
        while (mx < n) {
            ans++;
            ans += min(mx, n - mx);
            mx *= 2;
        }
        cout << ans << '\n';
    }

    return 0;
}