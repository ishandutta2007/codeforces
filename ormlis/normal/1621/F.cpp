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
const int maxN = 6e6 + 100;
const int LG = 20;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    ll ans = 0;
    int can1 = 0;
    vector<pair<int, int>> segs;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && s[j] == s[i]) j++;
        if (s[i] == '1') {
            can1 += j - i - 1;
        } else {
            int t = 1;
            if (i > 0 && j < n) t = 0;
            segs.emplace_back(t, j - i);
        }
    }
    sort(all(segs));
    for (int start = 0; start < 2; ++start) {
        ll cur = 0;
        int o1 = can1;
        if (start == 1) {
            if (can1 == 0) continue;
            cur += b;
            o1--;
        }
        ans = max(ans, cur);
        int h0 = 0;
        int tt = 0;
        bool bad = false;
        for (auto[t, len] : segs) {
            rep(_, len - 1) {
                ans = max(ans, cur + a);
                while (o1 == 0) {
                    if (h0 == 0) {
                        bad = true;
                        break;
                    }
                    h0--;
                    cur -= c;
                    cur += b;
                    ans = max(ans, cur);
                }
                ans = max(ans, cur + a);
                if (bad) break;
                cur += a;
                o1--;
                cur += b;
                ans = max(ans, cur);
            }
            if (bad) break;
            if (t == 0) h0++;
            else tt++;
        }
        if (bad) continue;
        while (h0 > 0) {
            h0--;
            cur -= c;
            cur += b;
            ans = max(ans, cur);
        }
        while(o1 > 0 && tt > 0) {
            cur -= c;
            cur += b;
            o1--;
            tt--;
            ans = max(ans, cur);
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
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