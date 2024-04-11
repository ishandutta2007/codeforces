#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int a[maxN];
int n;
ll k;

void solve() {
    cin >> n >> k;
    range(i, n) cin >> a[i];

    auto check = [&](ll x) {
        ll ans = 0;
        range(i, n) {
            ll l = 0, r = a[i] + 1;
            while(r - l > 1) {
                ll mid = (r + l) / 2;
                ll res = mid * mid * (-3) + mid * 3 + a[i] - 1;
                if (res >= x) l = mid;
                else r = mid;
            }
            ans += l;
        }
        return ans;
    };

    ll L = -INF, R = INF;
    while (R - L > 1) {
        ll mid = (R + L) / 2;
        if (check(mid) >= k) {
            L = mid;
        } else {
            R = mid;
        }
    }
    vector<ll> b(n);
    vector<pair<ll, int>> res(n);
    ll answer = 0;
    range(i, n) {
        ll l = 0, r = a[i] + 1;
        while(r - l > 1) {
            ll mid = (r + l) / 2;
            ll res = mid * mid * (-3) + mid * 3 + a[i] - 1;
            if (res >= L) l = mid;
            else r = mid;
        }
        b[i] = l;
        answer += l;
        if (l > 0) {
            res[i].first = l * l * (-3) + l * (-3) + a[i] - 1;
        } else {
            res[i].first = INF;
        }
        res[i].second = i;
    }
    sort(all(res));
    range(i, answer - k) b[res[i].second]--;
    range(i, n) cout << b[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}