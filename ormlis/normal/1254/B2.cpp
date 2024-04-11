#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll s = 0;
    range(i, n) {
        cin >> a[i];
        s += a[i];
    }

    ll ans = INF;
    vector<ll> divs;
    for (ll i = 2; i * i <= s; ++i) {
        if (s % i == 0) {
            divs.push_back(i);
            while (s % i == 0) {
                s /= i;
            }
        }
    }
    if (s != 1) divs.push_back(s);
    for (auto &x: divs) {
        ll res = 0;
        ll cur_res = 0;
        ll cur_res_mid = 0;
        for(int j = 0, mid = -1; j < n; ++j) {
            ll k = min(1ll * a[j], x - cur_res);
            cur_res += k;
            res += k * (j - mid);
            while (mid < j && cur_res_mid * 2 < cur_res) {
                res += cur_res_mid - (cur_res - cur_res_mid);
                mid++;
                cur_res_mid += a[mid];
            }
            if (j == n - 1) break;
            if (cur_res == x) {
                cur_res = (a[j] - k) % x;
                mid = j;
                cur_res_mid = cur_res;
            }
        }
        ans = min(ans, res);
    }
    if (ans == INF) cout << -1;
    else cout << ans;
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