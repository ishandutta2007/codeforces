#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001;
ll md = 1000000007;

void solve() {
    int n; cin >> n;
    vector<int> a(n), dp1(n), dp2(n);
    range(i, n) cin >> a[i];
    dp1[0] = dp2[0] = 1;
    int ans = 1;
    for(int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {dp1[i] = dp1[i - 1] + 1; dp2[i] = dp2[i - 1] + 1;}
        else dp1[i] = 1;
        if (i > 1 && a[i] > a[i - 2] + 1) dp2[i] = max(dp1[i - 2] + 1, dp2[i]);
        ans = max(ans, max(dp1[i]+1, dp2[i]+1));
    }
    cout << min(ans, n);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}