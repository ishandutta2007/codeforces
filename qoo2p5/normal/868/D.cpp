#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-8;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, f, t) for (int i = f; i < t; i++)
#define per(i, f, t) for (int i = f; i >= t; i--)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(12);
    run();
    return 0;
}

// == SOLUTION == //

const int N = 205;
const int K = 15;

struct String {
    string L, R;
    bool have[K + 1][1 << K];
    
    String() {
        L = "";
        R = "";
        memset(have, 0, sizeof have);
    }
    
    int answer() {
        int ans = 0;
        while (ans + 1 <= K) {
            bool ok = 1;
            rep(mask, 0, 1 << (ans + 1)) {
                ok &= have[ans + 1][mask];
            }
            if (!ok) break;
            else ans++;
        }
        return ans;
    }
};

int n, m;
String s[N];

void set_have(const string &t, String &s) {
    rep(i, 0, sz(t)) {
        int cur = 0;
        rep(j, i, min(sz(t), i + K)) {
            cur <<= 1;
            if (t[j] == '1') {
                cur |= 1;
            }
            s.have[j - i + 1][cur] = 1;
        }
    }
}

String read() {
    string t;
    cin >> t;
    String res;
    set_have(t, res);
    if (sz(t) <= K) {
        res.L = t;
    } else {
        res.L = t.substr(0, K);
        res.R = t.substr(sz(t) - K, K);
    }
    return res;
}

void make_or(String &a, String &b) {
    rep(len, 0, K + 1) {
        rep(mask, 0, 1 << len) {
            b.have[len][mask] |= a.have[len][mask];
        }
    }
}

String merge(String &a, String &b) {
    if (sz(a.R) == 0 && sz(b.R) == 0) {
        string t = a.L + b.L;
        String res;
        make_or(a, res);
        make_or(b, res);
        set_have(t, res);
        if (sz(t) <= K) {
            res.L = t;
        } else {
            res.L = t.substr(0, K);
            res.R = t.substr(sz(t) - K, K);
        }
        return res;
    } else if (sz(a.R) == 0) {
        string t = a.L + b.L;
        String res;
        make_or(a, res);
        make_or(b, res);
        set_have(t, res);
        res.R = b.R;
        res.L = t.substr(0, min(sz(t), K));
        return res;
    } else if (sz(b.R) == 0) {
        string t = a.R + b.L;
        String res;
        make_or(a, res);
        make_or(b, res);
        set_have(t, res);
        res.L = a.L;
        if (sz(t) <= K) {
            res.R = t;
        } else {
            res.R = t.substr(sz(t) - K, K);
        }
        return res;
    } else {
        string t = a.R + b.L;
        String res;
        make_or(a, res);
        make_or(b, res);
        set_have(t, res);
        res.L = a.L;
        res.R = b.R;
        return res;
    }
}

void run() {
    cin >> n;
    rep(i, 1, n + 1) {
        s[i] = read();
    }
    cin >> m;
    rep(i, 1, m + 1) {
        int a, b;
        cin >> a >> b;
        s[n + i] = merge(s[a], s[b]);
        cout << s[n + i].answer() << "\n";
    }
}