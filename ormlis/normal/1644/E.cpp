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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int X = n - 1;
    int Y = n - 1;
    for (auto &c : s) {
        if (c == 'R') X--;
        else Y--;
    }
    ll ans = 1;
    ar<int, 4> cur = {0, 0, 0, 0};
    int mask = 0;
    int x = 0, y = 0;
    for (auto &c : s) {
        if (c == 'R') {
            mask |= 1;
            x++;
        } else {
            mask |= 2;
            y++;
        }
        ar<int, 4> nxt = {x, y, x, y};
        if (mask & 1) {
            nxt[2] += X;
        }
        if (mask & 2) {
            nxt[3] += Y;
        }
        ans += 1ll * (nxt[2] - nxt[0] + 1) * (nxt[3] - nxt[1] + 1);
        ans -= 1ll * max(0, min(nxt[2], cur[2]) - max(nxt[0], cur[0]) + 1) *
               max(0, min(nxt[3], cur[3]) - max(cur[1], nxt[1]) + 1);
        swap(nxt, cur);
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