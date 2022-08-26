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
const int maxN = 2e5 + 10;

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    vi cur(1 << n);
    iota(all(cur), 1);
    while(cur.size() > 2) {
        vi nxt;
        for(int i = 0; i < cur.size(); i += 4) {
            int v = query(cur[i], cur[i + 2]);
            int x, y;
            if (v == 0) {
                x = cur[i + 1];
                y = cur[i + 3];
            } else if (v == 1) {
                x = cur[i];
                y = cur[i + 3];
            } else {
                x = cur[i + 1];
                y = cur[i + 2];
            }
            v = query(x, y);
            assert(v != 0);
            if (v == 1) {
                nxt.push_back(x);
            } else {
                nxt.push_back(y);
            }
        }
        cur = nxt;
    }
    if (cur.size() == 2) {
        if (query(cur[0], cur[1]) == 2) swap(cur[0], cur[1]);
    }
    cout << "! " << cur[0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}