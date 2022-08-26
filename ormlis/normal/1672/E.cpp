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
const int maxN = 4e5 + 10;
const int LG = 100;

int ask(int w) {
    cout << "? " << w << endl;
    int h;
    cin >> h;
    return h;
}

void solve() {
    int n;
    cin >> n;
    int L = n + (n - 1) - 1;
    int R = n * 2000 + (n - 1);
    int B = 0;
    while (R - L > 1) {
        int mid = (R + L) / 2;
        int r = ask(mid);
        if (r == 1) {
            R = mid;
        } else {
            if (r == 0) B = mid;
            L = mid;
        }
    }
    ll ans = R;
    int S = R - (n - 1);
    for (int h = 2; h <= n; ++h) {
        int S2 = (S + (n - h));
        int w2 = (S2 + h - 1) / h;
        while (1ll * w2 * h < ans) {
            if (w2 <= B) {
                w2++;
                continue;
            }
            int t = ask(w2);
            if (t != 0) ans = min(ans, 1ll * t * w2);
            else B = w2;
            if (t != h) {
                w2++;
                continue;
            }
            break;
        }
    }
    cout << "! " << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}