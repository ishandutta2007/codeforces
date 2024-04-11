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
using i128 = __int128;
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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e6 + 10;

void solve() {
    set<ar<ll, 3>> s;
    int n, t;
    cin >> n >> t;
    vi g(n), c(n), d(n - 1);
    rep(i, n) cin >> g[i] >> c[i];
    rep(i, n - 1) cin >> d[i];
    ll cur = 0;
    auto split = [&](ll pos) {
        ar<ll, 3> kek = {pos + 1, -1, -1};
        auto it = s.lower_bound(kek);
        assert(it != s.begin());
        it--;
        if ((*it)[0] == pos) return;
        auto cur = *it;
        s.erase(it);
        assert(cur[0] < pos && cur[1] > pos);
        s.insert({cur[0], pos, cur[2]});
        s.insert({pos, cur[1], cur[2]});
    };
    auto get_value = [&](ll pos) {
        ar<ll, 3> kek = {pos + 1, -1, -1};
        auto it = s.lower_bound(kek);
        if (it != s.begin()) {
            it--;
            return (*it)[2] + pos;
        } else {
            it = prev(s.end());
            ll l = (*it)[0];
            assert(l > pos);
            return (*it)[2] + t + pos;
        }
    };
    auto erase = [&](ll L, ll R) {
        ar<ll, 3> kek = {L, -1, -1};
        while (true) {
            auto it = s.lower_bound(kek);
            if (it == s.end()) break;
            if ((*it)[0] >= R) break;
            assert((*it)[1] <= R);
            s.erase(it);
        }
    };
    vl good = {0, t};
    rep(i, n) {
        if (i) cur -= d[i - 1];
        ll L = cur + g[i] - c[i];
        ll R = cur + t - c[i];
        L %= t;
        L = (L + t) % t;
        R %= t;
        R = (R + t) % t;
        good.push_back(L);
        good.push_back((L + 1) % t);
        good.push_back((L + t - 1) % t);
        good.push_back(R);
        good.push_back((R + 1) % t);
        good.push_back((R + t - 1) % t);
    }
    cur = 0;
    sort(all(good));
    good.resize(unique(all(good)) - good.begin());
    rep(i, (int)good.size() - 1) {
        s.insert({good[i], good[i + 1], -good[i]});
    }

    rep(i, n) {
        if (i) cur -= d[i - 1];
        ll L = cur + g[i] - c[i];
        ll R = cur + t - c[i];
        L %= t;
        L = (L + t) % t;
        R %= t;
        R = (R + t) % t;
        assert(L != R);
        split(L);
        split(R);
        if (L < R) {
            erase(L, R);
            ll v = get_value(L);
            s.insert({L, R, v - L});
        } else {
            swap(L, R);
            erase(R, t);
            erase(0, L);
            ll vR = get_value(R);
            ll vL = get_value(0);
            if (L != 0) s.insert({0, L, vL});
            s.insert({R, t, vR - R});
        }
    }
    ll ans = INF;
    assert(!s.empty());
    for (auto[l, r, v] : s) {
        ans = min(ans, v + l);
        ans = min(ans, v + t);
    }
    cout << ans + accumulate(all(d), 0ll) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}