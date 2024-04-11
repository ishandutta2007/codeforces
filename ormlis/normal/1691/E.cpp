#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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
const int maxN = 5e6 + 30;
const int LG = 100;


struct dsu {
    vector<int> dsu;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        return a == b;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ar<int, 3>> events;
    vi c(n), l(n), r(n);
    rep(i, n) {
        cin >> c[i] >> l[i] >> r[i];
        events.push_back({l[i], 0, i});
        events.push_back({r[i], 1, i});
    }
    dsu d;
    d.build(n);
    sort(all(events));
    ar<int, 2> cnt = {0, 0};
    set<int> have1, have2;
    int comps = n;
    for (auto &[x, tp, i] : events) {
        if (tp == 0) {
            cnt[c[i]]++;
            have2.insert(i);
        } else {
            have1.erase(i);
            have2.erase(i);
            cnt[c[i]]--;
        }
        if (cnt[0] != 0 && cnt[1] != 0) {
            for (auto &t : have2) {
                if (!have1.empty()) if (!d.unio(*have1.begin(), t)) comps--;
                have1.insert(t);
            }
            have2.clear();
        }
    }
    cout << comps << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}