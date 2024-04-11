#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 2e5 + 20;
const int LG = 30;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi l(m), r(m);
    rep(i, m) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }
    vvi L(n), R(n);
    rep(i, m) {
        L[l[i]].push_back(i);
        R[r[i]].push_back(i);
    }
    vi nxt(n, n);
    vi prv(n, -1);
    map<int, int> last;
    map<int, vector<int>> kek;
    rep(i, n) {
        if (last.count(a[i])) {
            prv[i] = last[a[i]];
            nxt[last[a[i]]] = i;
        }
        last[a[i]] = i;
        kek[a[i]].push_back(i);
    }
    vi toL(n, n + 1), toR(n, -1);
    bool was = false;
    {
        int need = -1;
        multiset<int> have;
        int mxL = n;
        rep(i, n) {
            need = max(need, i);
            if (i > mxL) break;
            toL[i] = need;
            for (auto &j : L[i]) have.insert(r[j]);
            if (!have.empty()) {
                int rr = *have.rbegin();
                if (nxt[i] <= rr) {
                    was = true;
                    mxL = min(mxL, nxt[i]);
                    vi &v = kek[a[i]];
                    int j = upper_bound(all(v), rr) - v.begin();
                    j--;
                    assert(j != -1);
                    int x = v[j];
                    assert(x != i);
                    need = max(need, x);
                }
            }
            for (auto &j : R[i]) have.erase(have.find(r[j]));
        }
    }
    if (!was) {
        cout << "0\n";
        return;
    }
    {
        int need = n + 1;
        multiset<int> have;
        int mnR = 0;
        for (int i = n - 1; i >= 0; --i) {
            need = min(need, i);
            if (i < mnR) break;
            toR[i] = need;
            for (auto &j : R[i]) have.insert(l[j]);
            if (!have.empty()) {
                int lt = *have.begin();
                if (prv[i] >= lt) {
                    mnR = max(mnR, prv[i]);
                    vi &v = kek[a[i]];
                    int j = lower_bound(all(v), lt) - v.begin();
                    assert(j != (int) v.size());
                    int x = v[j];
                    assert(x != i);
                    need = min(need, x);
                }
            }
            for (auto &j : L[i]) have.erase(have.find(l[j]));
        }
    }
    int ans = n;
    // L, R
    int j = 0;
    rep(i, n) {
        while (j < n && (toR[j] < i || j < toL[i])) j++;
        if (j == n) break;
        ans = min(ans, j - i + 1);
    }
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}