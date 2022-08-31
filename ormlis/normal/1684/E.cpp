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
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    rep(i, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int diff = cnt.size();
    multiset<int> have1;
    multiset<int> have2;
    int S = 0;
    for (auto &[x, y] : cnt) have2.insert(y);
    int need = 0;
    int ans = n;
    for (int mex = 0; mex <= n; ++mex) {
        if (cnt[mex] != 0) {
            int d = cnt[mex];
            {
                auto it = have2.find(d);
                if (it == have2.end()) {
                    have1.erase(have1.find(d));
                    S -= d;
                } else {
                    have2.erase(it);
                }
            }
            continue;
        }
        if (need > k) break;
        while (!have2.empty()) {
            int v = *have2.begin();
            if (v + S <= k) {
                have1.insert(v);
                have2.erase(have2.begin());
                S += v;
                continue;
            }
            break;
        }
        int cur = -mex;
        cur += diff - (int) have1.size() + need;
        ans = min(ans, cur);
        need++;
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