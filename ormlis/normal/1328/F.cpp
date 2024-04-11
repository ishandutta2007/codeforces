#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 200001;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    map<int, int> cnt;
    range(i, n) cnt[a[i]]++;
    sort(all(a));
    vector<ll> pref(n, 0), suf(n, 0);
    pref[0] = 0;
    for(int i = 1; i < n; ++i) pref[i] = pref[i-1] + 1ll * (a[i] - a[i-1]) * i;
    suf[n-1] = 0;
    for(int i = n - 2; ~i; --i) suf[i] = suf[i+1] + 1ll * (a[i+1] - a[i]) * (n - 1 - i);
    vector<int> used(n);
    ll ans = INF;
    range(i, n) {
        if (used[i]) continue;
        int j=i;
        while(j < n && a[j] == a[i]) {
            used[j] = 1;
            j++;
        }
        int curk = cnt[a[i]];
        ll curans = 0;
        if (curk >= k) {
            ans = 0;
            break;
        }
        int k1 = k - curk;
        if (i > 0 && i >= k1) {
            ans = min(ans, pref[i-1] + 1ll * (a[i] - 1 - a[i-1]) * i + k1);
        }
        if (j < n && n - j >= k1) {
            ans = min(ans, suf[j] + 1ll * (a[j] - a[j-1] - 1) * (n - j) + k1);
        }
        if (i > 0 && j < n) {
            ans = min(ans, pref[i-1] + 1ll * (a[i] - a[i-1] - 1) * i + suf[j] + 1ll * (a[j] - a[j-1] - 1) * (n - j) + k1);
        }
    }
    cout << ans;
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