#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 5e3 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> maxleft(n), minleft(n), maxright(n), minright(n);
    {
        int maxz = max(a[0], a[1]), minz = min(a[0], a[1]);
        maxleft[0] = maxleft[1] = minleft[0] = minleft[1] = a[0] * a[1];
        for (int i = 2; i < n; ++i) {
            maxleft[i] = maxleft[i - 1];
            minleft[i] = minleft[i - 1];
            if (a[i] <= 0) {
                maxleft[i] = max(maxleft[i], a[i] * minz);
                minleft[i] = min(minleft[i], a[i] * maxz);
            }
            if (a[i] >= 0) {
                minleft[i] = min(minleft[i], a[i] * minz);
                maxleft[i] = max(maxleft[i], a[i] * maxz);
            }
            maxz = max(maxz, a[i]);
            minz = min(minz, a[i]);
        }
    }
    {
        int maxz = max(a[n - 1], a[n - 2]), minz = min(a[n - 1], a[n - 2]);
        maxright[n - 1] = maxright[n - 2] = minright[n - 1] = minright[n - 2] = a[n - 1] * a[n - 2];
        for (int i = n - 3; i >= 0; --i) {
            maxright[i] = maxright[i + 1];
            minright[i] = minright[i + 1];
            if (a[i] <= 0) {
                maxright[i] = max(maxright[i], a[i] * minz);
                minright[i] = min(minright[i], a[i] * maxz);
            }
            if (a[i] >= 0) {
                minright[i] = min(minright[i], a[i] * minz);
                maxright[i] = max(maxright[i], a[i] * maxz);
            }
            maxz = max(maxz, a[i]);
            minz = min(minz, a[i]);
        }
    }
    ll ans = -INF;
    for (int i = 2; i <= n - 3; ++i) {
        ans = max(ans, max(1ll * maxleft[i - 1] * a[i] * maxright[i + 1],
                           1ll * minleft[i - 1] * a[i] * minright[i + 1]));
        ans = max(ans, max(1ll * minleft[i - 1] * a[i] * maxright[i + 1],
                           1ll * maxleft[i - 1] * a[i] * minright[i + 1]));
    }
    range(i, n) if (a[i] == 0) ans = max(ans, 0ll);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}