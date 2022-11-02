#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int sz = 2e5 + 5;
ll dp[sz];
bitset<sz> of;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (!of[n] && dp[n] < k) {
        cout << -1 << '\n';
        return;
    }
    ll rk = k;
    vector<int> ans(n);
    int i = 0, crn = 1, cand = 1, len = n;
    while (i < n) {
        if (of[len - 1]) {
            ans[i++] = cand++;
            crn = cand;
            len--;
        }
        else if (k <= dp[len - 1]) {
            ans[i++] = cand++;
            crn++;
            len--;
        }
        else {
            while (k > dp[len - (cand - crn + 1)]) {
                k -= dp[len - (cand - crn + 1)];
                cand++;
            }
            int tmp = cand;
            while (i < n && tmp >= crn) {
                ans[i++] = tmp--;
                len--;
            }
            cand++;
            crn = cand;
        }
    }
    for (int x : ans)cout << x << ' ';
    cout << '\n';
}

void prec() {
    dp[0] = 1;
    ll sum = 1;
    bool bad = 0;
    foru(i, 1, sz) {
        dp[i] = sum;
       
        if (bad || sum > 1e18) {
            bad = 1;
            of[i] = 1;
        }
        sum += dp[i];
    }
}

int main() {
    fast;
    prec();
    int t;
    cin >> t;
    while (t--)solve();

    return 0;
}