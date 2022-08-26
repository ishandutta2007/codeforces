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
const int maxN = 4e5;



void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    range(i, n) {
        int l1 = lower_bound(all(a), l - a[i]) - a.begin();
        int r1 = upper_bound(all(a), r - a[i]) - a.begin();
        ans += r1 - l1;
        if (l1 <= i && r1 > i) ans--;
    }
    cout << ans / 2 << '\n';
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