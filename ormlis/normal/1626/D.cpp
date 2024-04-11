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
const int maxN = 2e5 + 5;
const int LG = 20;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vi cnt(n);
    rep(i, n) {
        int x;  cin >> x;
        cnt[x - 1]++;
    }
    for(int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
    int ans = INFi;
    auto check_need = [&] (int x) {
        if (x == 0) return 1;
        if (x == 1) return 0;
        int y = 1 << (__lg(x - 1) + 1);
        return y - x;
    };
    rep(i, n) {
        int a = cnt[i];
        int b = n - cnt[i];
        ans = min(ans, check_need(a) + check_need(b) + check_need(0));
    }
    ans = min(ans, 2 + check_need(n));
    vi p(n);
    rep(i, n) {
        p[i] = check_need(cnt[i]) + cnt[i];
    }
    multiset<int> values;
    vector<int> uk(LG, 0);
    vi to(LG);
    rep(i, LG - 1) to[i + 1] = (1 << i);
    to[0] = -1;
    for(int y = 1; y < n; ++y) {
        int res = check_need(n - cnt[y]);
        rep(i, LG) {
            while(uk[i] < y && cnt[y] - cnt[uk[i]] > to[i]) {
                int j = uk[i]++;
                if (i != 0) {
                    values.erase(values.find(p[j] + (1 << (i - 1))));
                }
                values.insert(p[j] + (1 << i));
            }
        }
        ans = min(ans, res + *values.begin() - cnt[y]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}