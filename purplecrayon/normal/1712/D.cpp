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
        auto b = a; int cnt = 0;
        for (int i = 0; i < n; i++) if (2 * a[i] < x) {
            cnt++;
            b[i] = 1e9;
        }
        int need = 2;
        for (int i = 0; i < n-1; i++) {
            int cur = (b[i] < x) + (b[i+1] < x);
            need = min(need, cur);
        }

        return cnt + need <= k;
    };

    int lo = -1, hi = 1e9 + 10, mid = (lo + hi) / 2;
    while (lo < mid && mid < hi) {
        if (can(mid)) lo = mid;
        else hi = mid;
        mid = (lo + hi) / 2;
    }
    cout << min(int(1e9), lo) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}