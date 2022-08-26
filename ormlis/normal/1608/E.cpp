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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5;
const int LG = 30;

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
};

int lower_bound(fenwick &f1, fenwick &f2) {
    int r = -1;
    ll x = f2.get(f2.n - 1);
    for (int j = 20; j >= 0; --j) {
        int t = (1 << j);
        if (r + t >= f1.n) continue;
        if (f2.fenw[r + t] + f1.fenw[r + t] >= x) continue;
        r += t;
        x -= f2.fenw[r] + f1.fenw[r];
    }
    return r + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<ar<int, 3>> a(n);
    rep(i, n) rep(j, 3) cin >> a[i][j];
    vector<int> xx, yy;
    rep(i, n) {
        xx.push_back(a[i][0]);
        yy.push_back(a[i][1]);
        a[i][2]--;
    }
    sort(all(xx));
    sort(all(yy));
    xx.resize(unique(all(xx)) - xx.begin());
    yy.resize(unique(all(yy)) - yy.begin());
    rep(i, n) {
        a[i][0] = lower_bound(all(xx), a[i][0]) - xx.begin();
        a[i][1] = lower_bound(all(yy), a[i][1]) - yy.begin();
    }
    int ans = 0;
    rep(_, 2) {
        sort(all(a));
        rep(__, 2) {
            vector<fenwick> ct(3);
            rep(i, 3) ct[i].build(n);
            rep(i, n - 1) {
                auto[x, y, c] = a[i];
                ct[c].upd(y, 1);
                if (a[i + 1][0] == x) continue;
                rep(colR, 3) {
                    rep(colD, 3) {
                        if (colD == colR) continue;
                        int colU = 3^(colD ^ colR);
                        int ctR = n/3 - ct[colR].get(n - 1);
                        int j = lower_bound(ct[colD], ct[colU]);
                        for(int k = j - 3; k <= j + 3; ++k) {
                            if (k <= 0 || k > n) continue;
                            int ctD = ct[colD].get(k - 1);
                            int ctU = ct[colU].get(n - 1) - ct[colU].get(k - 1);
                            ans = max(ans, min({ctD, ctU, ctR}));
                        }
                    }
                }
            }
            reverse(all(a));
        }
        rep(colL, 3) {
            rep(colR, 3) {
                if (colL == colR) continue;
                int colMid = (colL ^ colR) ^ 3;
                int cntL = 0, cntR = 0;
                int cntMid = n / 3;
                int L = 0, R = n - 1;
                for(int d = 1; d <= n / 3; ++d) {
                    while(cntL < d) {
                        do {
                            int c = a[L++][2];
                            if (c == colL) cntL++;
                            if (c == colMid) cntMid--;
                        } while(L < n && a[L][0] == a[L - 1][0]);
                    }
                    while(cntR < d) {
                        do {
                            int c = a[R--][2];
                            if (c == colR) cntR++;
                            if (c == colMid) cntMid--;
                        } while(R >= 0 && a[R][0] == a[R + 1][0]);
                    }
                    if (cntMid < d) break;
                    ans = max(ans, d);
                }
            }
        }
        rep(i, n) swap(a[i][0], a[i][1]);
    }
    cout << ans * 3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}