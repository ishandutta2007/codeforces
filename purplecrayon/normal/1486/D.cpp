#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;

    auto can = [&](int x) {
        vector<int> b(n + 1);
        vector<int> mn(n + 1);
        for (int i = 0; i < n; i++) {
            b[i+1] = (a[i] >= x ? +1 : -1);
            b[i+1] += b[i];
            mn[i+1] = min(mn[i], b[i+1]);
        }
        // segment with len >= k with positive sum
        // ps[r] - ps[l] >= 0 && r - l >= k
        for (int r = k; r <= n; r++) {
            if (mn[r - k] < b[r])
                return true;
        }
        return false;
    };

    int lo = -1, hi = n + 1, mid = (lo + hi) / 2;
    while (lo < mid && mid < hi) {
        if (can(mid)) lo = mid;
        else hi = mid;
        mid = (lo + hi) / 2;
    }
    cout << lo << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}