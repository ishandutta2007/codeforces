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
const int maxN = 1e7 + 30;
const int LG = 100;

void solve() {
    int n;
    cin >> n;
    bool answered = false;
    auto query = [&](int i, int j, int k) {
        if (answered) return -1;
        assert(i != j && j != k && k != i);
        cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
        int x;
        cin >> x;
        return x;
    };
    auto answer = [&](int i, int j) {
        if (answered) return;
        answered = true;
        cout << "! ";
        cout << i + 1 << ' ' << j + 1 << endl;
    };
    int nxt = 1;
    auto get_max = [&](int i, int j, bool tr) {
        assert(i != j);
        int mx = -2;
        int f = -2;
        int cnt = 0;
        vector<int> to;
        rep(k, n) {
            if (k == i || k == j) continue;
            int cur = query(i, j, k);
            if (cur > mx) {
                mx = cur;
                cnt = 0;
                f = k;
                to.clear();
            }
            if (cur == mx) {
                to.push_back(k);
                cnt++;
            }
        }
        if (cnt < n - 2) return f;
        int a = to[0];
        int b = to[1];
        if (!tr) {
            answer(i, j);
            return i;
        }
        int val1 = query(i, a, b);
        int val2 = query(j, a, b);
        if (max(val1, val2) > mx) return f;
        if (max(val1, val2) < mx) {
            answer(i, j);
            return i;
        }
        if (min(val1, val2) == mx) return f;
        if (val1 == mx) {
            nxt = j;
            return f;
        }
        nxt = i;
        return f;
    };
    int i = get_max(0, 1, true);
    int j = get_max(i, nxt, false);
    answer(i, j);
}

signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}