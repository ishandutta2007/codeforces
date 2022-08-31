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
const int LG = 19;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vi a(n);
    vi b(n);
    rep(i, n) {
        int x; cin >> x;
        a[x-1]++;
        b[i] = x-1;
    }
    int r = 0;
    int cnt = 0;
    ar<int, 3> ans = {n - 1, 0, n - 1};
    for(int l = 0; l < n; ++l) {
        while(r < n && cnt - (n - cnt) < k) {
            cnt += a[r];
            r++;
        }
        if (cnt - (n - cnt) < k) break;
        ans = min(ans, {r - l - 1, l, r - 1});
        cnt -= a[l];
    }
    cout << ans[1] + 1 << ' ' << ans[2] + 1 << '\n';
    vector<pair<int, int>> answ;
    int L = 0;
    int c = 0;
    for(int i = 0; i < n; ++i) {
        if (answ.size() == k - 1) break;
        if (ans[1] <= b[i] && b[i] <= ans[2]) c++;
        else c--;
        if (c == (int)answ.size() + 1) {
            answ.emplace_back(L, i);
            L = i + 1;
        }
    }
    answ.emplace_back(L, n - 1);
    for(auto &[l, r] : answ) cout << l + 1 << ' ' << r + 1 << '\n';
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