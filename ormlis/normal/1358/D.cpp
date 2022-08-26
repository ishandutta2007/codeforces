#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; ll x; cin >> n >> x;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int l = 0;
    ll cur = 0;
    ll ob = 0;
    ll ans = 0;
    range(r, n) {
        cur += a[r];
        ob += 1LL * a[r] * (a[r] + 1) / 2;
        while(cur < x) {
            l--;
            if (l == -1) l = n - 1;
            cur += a[l];
            ob += 1LL * a[l] * (a[l] + 1) / 2;
        }
        while(cur - a[l] >= x) {
            cur -= a[l];
            ob -= 1LL * a[l] * (a[l] + 1) / 2;
            l++;
            if (l == n) l = 0;
        }
        ll t = cur - x;
        ll curob = ob - 1LL * t * (t + 1) / 2;
        ans = max(ans, curob);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}