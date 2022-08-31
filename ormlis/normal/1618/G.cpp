#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
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

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vpi a(n), b(m);
    rep(i, n) cin >> a[i].first;
    rep(i, m) cin >> b[i].first;
    rep(i, n) a[i].second = 0;
    rep(i, m) b[i].second = 1;
    sort(all(a));
    sort(all(b));
    vpi c(n + m);
    merge(all(a), all(b), c.begin());
    vector<int> r(n + m - 1);
    iota(all(r), 1);
    sort(all(r), [&] (const int &i, const int &j) {
        return c[i].first - c[i - 1].first < c[j].first - c[j - 1].first;
    });
    vector<ll> pref(n + m + 1);
    rep(i, n + m) pref[i + 1] = pref[i] + c[i].first;
    ll cur = 0;
    rep(i, n) cur += a[i].first;
    vector<pair<ll, ll>> answers;
    map<int, int> cnt;
    rep(i, n + m) {
        if (c[i].second == 0) cnt[i] = 1;
        else cnt[i] = 0;
    }
    auto get = [&] (int i) {
        auto it = cnt.upper_bound(i);
        int l = i;
        int r = n + m;
        if (it != cnt.end()) r = it->first;
        int x = cnt[i];
        return pref[r] - pref[r - x];
    };
    answers.emplace_back(0, cur);
    for(auto &i : r) {
        ll rz = c[i].first - c[i - 1].first;
        auto it = cnt.find(i);
        it--;
        int j = it->first;
        cur -= get(i) + get(j);
        cnt[j] += cnt[i];
        cnt.erase(i);
        cur += get(j);
        answers.emplace_back(rz, cur);
    }
    rep(_, q) {
        int k; cin >> k;
        pair<ll, ll> tmp = {k + 1, -1};
        int j = lower_bound(all(answers), tmp) - answers.begin();
        j--;
        cout << answers[j].second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    rep(_, t) {
        solve();
    }
    return 0;
}