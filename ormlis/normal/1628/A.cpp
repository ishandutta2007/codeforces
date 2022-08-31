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
const int maxN = 3e5 + 5;
const int LG = 20;

void solve() {
    int n; cin >> n;
    vvi have(n + 2);
    vi a(n);
    rep(i, n) cin >> a[i];
    for(int i = n - 1; i >= 0; --i) have[a[i]].push_back(i);
    int l = 0;
    vi ans;
    while(l < n) {
        int r = l;
        for(int t = 0; t <= n + 1; ++t) {
            if (have[t].empty()) {
                ans.push_back(t);
                break;
            }
            r = max(r, have[t].back());
        }
        r++;
        for(int i = l; i < r; ++i) {
            have[a[i]].pop_back();
        }
        l = r;
    }
    cout << ans.size() << '\n';
    for(auto &x : ans) cout << x << ' ';
    cout << '\n';
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