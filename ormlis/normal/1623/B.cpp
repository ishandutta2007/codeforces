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
const int maxN = 605;
const int LG = 20;

void solve() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return make_pair(r[i] - l[i], l[i]) > make_pair(r[j] - l[j], l[j]);
    });
    vi cnt(n);
    rep(i, n) for(int j = l[i] - 1; j < r[i]; ++j) cnt[j]++;
    for(auto &i : ord) {
        for(int j = l[i] - 1; j < r[i]; ++j) {
            cnt[j]--;
            if (cnt[j] == 0) {
                cout << l[i] << ' ' << r[i] << ' ' << j + 1 << '\n';
            }
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}