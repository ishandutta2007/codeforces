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
const int maxN = (1 << 20) + 1;
const int maxP = 1000;
const int LG = 30;

int b[32][32];
int c[32][32];

void revers2(int n) {
    rep(i, n / 2) {
        rep(j, n) {
            swap(c[i][j], c[n - 1 - i][j]);
        }
    }
}

void revers1(int n) {
    rep(i, n) {
        rep(j, n / 2) {
            swap(c[i][j], c[i][n - 1 - j]);
        }
    }
}


void build() {
    for (int n = 1; n <= 16; n *= 2) {
        int D = n * n;
        rep(i, n) rep(j, n) c[i][j] = b[i][j];
        revers1(n);
        rep(i, n) rep(j, n) b[i][j + n] = c[i][j] + D;
        revers2(n);
        rep(i, n) rep(j, n) b[i + n][j + n] = c[i][j] + (D * 3);
        revers1(n);
        rep(i, n) rep(j, n) b[i + n][j] = c[i][j] + D * 2;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll s = 0;
    build();
    rep(i, n) {
        rep(j, n - 1) {
            cout << (b[i][j] ^ b[i][j + 1]) << ' ';
            s += (b[i][j] ^ b[i][j + 1]);
        }
        cout << endl;
    }
    rep(i, n - 1) {
        rep(j, n) {
            cout << (b[i][j] ^ b[i + 1][j]) << ' ';
            s += (b[i][j] ^ b[i + 1][j]);
        }
        cout << endl;
    }
    rep(_, k) {
        int x;
        cin >> x;
        rep(i, n) {
            rep(j, n) {
                if (b[i][j] == x) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
                b[i][j] ^= x;
            }
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}