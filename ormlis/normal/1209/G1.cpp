#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

void solve() {
    vector<pair<int, int>> segs;
    map<int, int> ft, lt;
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n);
    range(i, n) {
        cin >> a[i];
        lt[a[i]] = i;
    }
    for(int i = n - 1; i >= 0; --i) {
        ft[a[i]] = i;
    }
    for(auto &[c, p] : ft) {
        segs.emplace_back(p, lt[c]);
    }
    sort(all(segs));
    vector<pair<int, int>> segs2;
    for(auto &[l, r] : segs) {
        if (segs2.empty() || segs2.back().second < l) {
            segs2.emplace_back(l, r);
        }
        segs2.back().second = max(segs2.back().second, r);
    }
    int ans = 0;
    for(auto &[l, r] : segs2) {
        map<int, int> cnt;
        for(int i = l; i <= r; ++i) {
            cnt[a[i]]++;
        }
        int need = r - l + 1;
        for(auto &[x, c] : cnt) {
            need = min(need, r - l + 1 - c);
        }
        ans += need;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;

    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}