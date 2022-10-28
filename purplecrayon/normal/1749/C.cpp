#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());

    auto v = [&](int k) {
        vector<bool> use(n);
        for (int c = k; c >= 1; c--) {
            bool done = 0;
            for (int i = n-1; i >= 0 && !done; i--) {
                if (a[i] <= c && !use[i]) {
                    done = 1;
                    use[i] = 1;
                }
            }
            if (!done) {
                return false;
            }

            for (int i = 0; i < n; i++) {
                if (!use[i]) {
                    use[i] = 1;
                    break;
                }
            }
        }
        return true;
    };

    int lo = -1, hi = n + 1, mid = (lo + hi) / 2;
    while (lo < mid && mid < hi) {
        if (v(mid)) lo = mid;
        else hi = mid;
        mid = (lo + hi) / 2;
    }
    cout << lo << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}