#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(rall(a));
    ll ans = 0;
    ll komb = 0;
    int j = n;
    range(i, n) {
        ans += komb;
        komb += a[i];
        if (komb < 0) {
            j = i;
            a[j] = komb;
            break;
        }
    }
    int otr = k + 1;
    int cur = 0;
    ll tans = 0;
    vector<vector<int>> kek(k + 1);
    for(int i = n - 1; i >= j; --i) {
        int pos = kek[cur].size();
        tans += 1ll * pos * a[i];
        kek[cur].push_back(a[i]);
        cur++;
        if (cur == otr) cur = 0;
    }
    cout << ans + tans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}