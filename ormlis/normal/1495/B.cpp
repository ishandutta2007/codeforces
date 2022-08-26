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
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    range(i, n) cin >> p[i];
    vector<int> upl(n), upr(n), downl(n), downr(n);
    for(int i = 1; i < n; ++i) {
        if (p[i] > p[i - 1]) downl[i] = downl[i - 1] + 1;
        else upl[i] = upl[i - 1] + 1;
    }
    for(int i = n - 2; i >= 0; --i) {
        if (p[i] > p[i + 1]) downr[i] = downr[i + 1] + 1;
        else upr[i] = upr[i + 1] + 1;
    }
    int ans = 0;
    multiset<int> has;
    range(i, n) {
        has.insert(upl[i]);
        has.insert(upr[i]);
    }
    range(i, n) {
        if (!downl[i] || !downr[i]) continue;
        has.erase(has.find(downl[i]));
        has.erase(has.find(downr[i]));
        int mx = *has.rbegin();
        if (mx >= downl[i] && mx >= downr[i]) {
            has.insert(downl[i]);
            has.insert(downr[i]);
            continue;
        }
        int w = max(downl[i], downr[i]);
        int t = min(downl[i], downr[i]);
        if (w % 2 || w > t) {
            has.insert(downl[i]);
            has.insert(downr[i]);
            continue;
        }
        ans++;
        has.insert(downl[i]);
        has.insert(downr[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}