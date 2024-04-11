#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <tuple>
#include <queue>
#include <set>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    vector<int> x(n), y(n);
    range(i, n ) cin >> x[i];
    range(i, n ) cin >> y[i];
    sort(all(x));
    vector<int> dpl(n), dpr(n);;
    int l = 0;
    dpl[0] = 1;
    for(int r = 1; r < n; ++r) {
        while(x[r] - x[l] > k) l++;
        dpl[r] = max(dpl[r-1], r - l + 1);
    }
    dpr[n-1] = 1;
    int r = n - 1;
    for(int le = n - 2; le >= 0; --le) {
        while(x[r] - x[le] > k) r--;
        dpr[le] = max(dpr[le+1], r - le + 1);
    }
    int ans = 1;
    range(i, n - 1) ans = max(ans, dpl[i] + dpr[i+1]);
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