#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5;

void solve() {
    int n, W; cin >> n >> W;
    map<int, int> cnt;
    int cur = 0;
    range(i, n) {
        int x; cin >> x;
        cnt[-x]++;
    }
    int ans = 0;
    while(cur < n) {
        int d = W;
        for(auto &[x, cc] : cnt) {
            int f = min(cc, d / (-x));
            d += x * f;
            cc -= f;
            cur += f;
        }
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cout << setprecision(15) << fixed;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}