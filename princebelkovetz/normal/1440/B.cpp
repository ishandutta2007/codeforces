#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, k; cin >> n >> k;
        vector <int> a(n * k);
        for (auto& x : a) cin >> x;
        int ans = 0;
        int x = n / 2 + 1;
        int ind = 0;
        for (int i = 0; i < k; ++i) {
            ind += n - x;
        }
        for (int i = 0; i < k; ++i) {
            ans += a[ind];
            ind += x;
        }
        cout << ans << '\n';
    }
	return 0;
}