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

using int128 = __int128;
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

struct FSegTree {
    vector<int128> t;
    int n;

    void build(int k) {
        n = k;
        t.resize(n * 2 + 2, 1);
    }

    void upd(int i, int128 x) {
        for (t[i += n] = x; i > 1; i >>= 1) t[i >> 1] = t[i] * (t[i ^ 1] / __gcd(t[i], t[i ^ 1]));
    }

    // [l, r)
    int128 get() {
        int128 result = 1;
        for (int l = n, r = 2 * n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                result = result * (t[l] / __gcd(t[l], result));
                l++;
            }
            if (r & 1) {
                r--;
                result = result * (t[r] / __gcd(t[r], result));
            }
        }
        return result;
    }
};

int128 readInt() {
    string s;
    cin >> s;
    int128 value = 0;
    for (auto &c : s) {
        if ('0' <= c && c <= '9') {
            value *= 10;
            value += c - '0';
        }
    }
    if (s[0] == '-') return -value;
    return value;
}


const ll BASE = 1e18;

void printInt(int128 x) {
    vector<ll> res;
    while (x != 0) {
        ll cur = x % BASE;
        x /= BASE;
        res.push_back(cur);
    }
    reverse(all(res));
    rep(i, (int) res.size()) {
        ll val = res[i];
        if (i == 0) {
            cout << val;
            continue;
        }
        auto s = to_string(val);
        reverse(all(s));
        while (s.size() != 18) s += '0';
        reverse(all(s));
        cout << s;
    }

}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int128> a(n), b(m);
    rep(i, n) a[i] = readInt();
    rep(i, m) b[i] = readInt();
    vector<FSegTree> A(n), B(m);
    rep(i, n) A[i].build(m);
    rep(j, m) B[j].build(n);
    rep(i, n) {
        rep(j, m) {
            int128 g = __gcd(a[i], b[j]);
            A[i].upd(j, g);
            B[j].upd(i, g);
        }
    }
    queue<pair<int, int>> q;
    vector<bool> usedA(n, true), usedB(m, true);
    rep(i, n) {
        if (A[i].get() < a[i]) {
            usedA[i] = false;
            q.push({0, i});
        }
    }
    rep(i, m) {
        if (B[i].get() < b[i]) {
            usedB[i] = false;
            q.push({1, i});
        }
    }
    while (!q.empty()) {
        auto[t, i] = q.front();
        q.pop();
        if (t == 0) {
            rep(j, m) {
                B[j].upd(i, 1);
                if (usedB[j] && B[j].get() < b[j]) {
                    usedB[j] = false;
                    q.push({1, j});
                }
            }
        } else {
            rep(j, n) {
                A[j].upd(i, 1);
                if (usedA[j] && A[j].get() < a[j]) {
                    usedA[j] = false;
                    q.push({0, j});
                }
            }
        }
    }
    vector<int> Av, Bv;
    rep(i, n) {
        if (usedA[i]) Av.push_back(i);
    }

    rep(i, m) {
        if (usedB[i]) Bv.push_back(i);
    }
    if (Av.empty() || Bv.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << Av.size() << ' ' << Bv.size() << '\n';
    for (auto &x : Av) {
        printInt(a[x]);
        cout << ' ';
    }
    cout << '\n';

    for (auto &x : Bv) {
        printInt(b[x]);
        cout << ' ';
    }
    cout << '\n';
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