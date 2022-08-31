#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    priority_queue<int> pq;

    int ans = 0;
    ll sum = 0;
    while (n--) {
        int x; cin >> x;
        sum += x, ans++;
        if (x < 0) pq.push(-x);
        while (sum < 0) {
            sum += pq.top(); pq.pop();
            ans--;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}