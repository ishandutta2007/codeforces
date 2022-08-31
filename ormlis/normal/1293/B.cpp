 
 
#include <bits/stdc++.h>
 
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 998244353;
 
void solve() {
    double ans = 0, n; cin >> n;
    for(double i = n; i >= 1.0; i -= 1.0) {
        ans += 1.0 / i;
    }
    cout << setprecision(15) << fixed << ans;
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