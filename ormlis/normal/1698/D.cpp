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
const int maxN = 5e5 + 20;
const int LG = 30;

void solve() {
    auto ask = [&](int l, int r) {
        cout << "? " << l + 1 << ' ' << r << endl;
        int cnt = 0;
        rep(i, r - l) {
            int x;
            cin >> x;
            if (x > l && x <= r) {
                cnt++;
            }
        }
        return cnt;
    };
    int L = 0;
    int R;
    cin >> R;
    while (R - L > 1) {
        int mid = (R + L) / 2;
        if (ask(mid, R) % 2 == 1) {
            L = mid;
        } else {
            R = mid;
        }
    }
    cout << "! " << R << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}