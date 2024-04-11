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

pair<int, int> get_h(vector<int> &a, int n) {
    vector<int> pos(n);
    range(i, n) pos[a[i]] = i;
    set<int> alive;
    range(i, n) alive.insert(i);
    vector<int> h(n);
    for(int i = n - 1; i >= 1; --i) {
        int p = pos[i];
        alive.erase(p);
        auto it = alive.lower_bound(p);
        int to = -1;
        if (it != alive.end()) {
            to = max(to, a[*it]);
        }
        if (it != alive.begin()) {
            it--;
            to = max(to, a[*it]);
        }
        assert(to != -1);
        h[to] = max(h[to], h[i] + 1);
    }
    int l = -1;
    int r = -1;
    range(i, pos[0]) l = max(l, h[a[i]]);
    for(int i = pos[0] + 1; i < n; ++i) r = max(r, h[a[i]]);
    return {l, r};
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) a[i]--;
    int mn = min_element(all(a)) - a.begin();
    int L = -mn - 1, R = n - mn;
    pair<int, int> ans = {INFi, -1};
    while(R - L > 1) {
        int mid = (R + L) / 2;
        vector<int> b(n);
        range(i, n) {
            int j = i + mid;
            if (j < 0) j += n;
            if (j >= n) j -= n;
            b[j] = a[i];
        }
        auto [lp, rp] = get_h(b, n);
        ans = min(ans, {max(lp, rp) + 2, (-mid + n) % n});
        if (lp >= rp) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}