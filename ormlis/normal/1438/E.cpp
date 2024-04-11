#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    int ans = 0;
    range(_, 2) {
        range(r, n) {
            ll s = 0;
            for (int l = r - 2; l >= 0; --l) {
                s += a[l + 1];
                if (s > a[r] * 2) break;
                if (a[l] > a[r]) continue;
                if ((a[l] ^ a[r]) == s) ans++;
            }
        }
        reverse(all(a));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}