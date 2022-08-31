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
const int maxN = 5e3;
const int LG = 100;
const int md = 998244353; //1e9 + 7, 1e9 + 9

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

void solve() {
    int n;
    cin >> n;
    int R = 21;
    int C = 360;
    vector<vector<ar<int, 4>>> go(R, vector<ar<int, 4>>(C, {0, 0, 0, 0}));
    rep(i, n) {
        char x;
        cin >> x;
        if (x == 'C') {
            int r, a1, a2;
            cin >> r >> a1 >> a2;
            while (a1 != a2) {
                go[r][a1][0] = 1;
                go[r - 1][a1][2] = 1;
                a1 = (a1 + 1) % 360;
            }
        } else {
            int r1, r2, a;
            cin >> r1 >> r2 >> a;
            int a1 = (a - 1 + 360) % 360;
            for (int j = r1; j < r2; ++j) {
                go[j][a1][3] = 1;
                go[j][a][1] = 1;
            }
        }
    }
    queue<pair<int, int>> q;
    vvi was(R, vi(C, 0));
    q.push({R - 1, 0});
    was[R - 1][0] = 1;
    while (!q.empty()) {
        auto[i, j] = q.front();
        q.pop();
        if (i == 0) {
            cout << "YES\n";
            return;
        }
        rep(d, 4) {
            if (go[i][j][d] == 1) continue;
            int i1 = i + di[d];
            int j1 = (j + dj[d] + 360) % 360;
            if (i1 >= R) continue;
            if (was[i1][j1]) continue;
            was[i1][j1] = 1;
            q.push({i1, j1});
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}