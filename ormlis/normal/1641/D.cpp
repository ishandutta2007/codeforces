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
const int maxN = 1e6 + 30;
const int LG = 100;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> w(n);
    rep(i, n) {
        rep(j, m) cin >> a[i][j];
        cin >> w[i];
        sort(all(a[i]));
    }
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) { return w[i] < w[j]; });
    ll ANS = INF;
    vector<ar<int, 5>> have;
    rep(i, n) {
        rep(mask, 1 << m) {
            ar<int, 5> cur = {-1, -1, -1, -1, -1};
            int uk = 0;
            rep(j, m) {
                if ((1 << j) & mask) cur[uk++] = a[i][j];
            }
            have.push_back(cur);
        }
    }
    sort(all(have));
    have.resize(unique(all(have)) - have.begin());
    int sz = have.size();
    vector<int> cnt(sz);
    vector<vector<pair<int, int>>> to(n);
    rep(i, n) {
        rep(mask, 1 << m) {
            ar<int, 5> cur = {-1, -1, -1, -1, -1};
            int uk = 0;
            rep(j, m) {
                if ((1 << j) & mask) cur[uk++] = a[i][j];
            }
            int j = lower_bound(all(have), cur) - have.begin();
            cnt[j]++;
            to[i].emplace_back(j, __builtin_popcount(mask));
        }
    }
    auto del = [&](int i) {
        for (auto &[j, ct] : to[i]) {
            cnt[j]--;
        }
    };
    vector<vector<int>> C(m + 1, vector<int>(m + 1));
    C[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    vector<int> coef(m + 1, 1);
    vector<int> nd(m + 1, 1);
    for (int k = 1; k <= m; ++k) {
        int need = -coef[k];
        nd[k] = need;
        for (int t = k; t <= m; ++t) {
            coef[t] += need * C[t][k];
        }
    }
    auto cou = [&](int i) {
        int res = 0;
        for (auto &[j, ct] : to[i]) {
            res += nd[ct] * cnt[j];
        }
        return res;
    };
    int u = n - 1;
    for (auto &i : ord) {
        while (u >= 0 && w[ord[u]] + w[i] >= ANS) del(ord[u--]);
        if (u == -1) break;
        while (cou(i) > 0) {
            ANS = w[ord[u]] + w[i];
            del(ord[u--]);
        }
    }
    if (ANS == INF) {
        cout << "-1\n";
        return;
    }
    cout << ANS << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}