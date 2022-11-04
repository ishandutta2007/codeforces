#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;
const ll MOD = (ll) 1e9 + 7;
const ld EPS = 1e-9;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back

bool mini(auto &x, const auto &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}

bool maxi(auto &x, const auto &y) {
    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

#define int long long

const int N = (int) 1e5 + 123;
const int L = 60;

struct Node {
    int cnt;
    int to[2];
};

int ptr = 1;
Node t[N * L + 100];

bool test(int mask, int bit) {
    return mask & (1LL << bit);
}

void add(int x, int c) {
    int v = 0;
    per(i, L - 1, 0) {
        bool bit = test(x, i);
        if (!t[v].to[bit]) {
            t[v].to[bit] = ptr++;
        }
        v = t[v].to[bit];
        t[v].cnt += c;
    }
}

bool chk(int x) {
    int v = 0;
    per(i, L - 1, 0) {
        bool bit = test(x, i);
        if (!t[v].to[bit]) {
            t[v].to[bit] = ptr++;
        }
        v = t[v].to[bit];
    }
    return t[v].cnt > 0;
}

int get(int x, int v = 0, int pos = L - 1, bool eq = 1, int cur = 0) {
    if (v != 0) {
        assert(t[v].cnt > 0);
    }
    if (pos == -1) {
        return x;
    }
    bool bit = test(x, pos);
    if (!eq) {
        if (t[t[v].to[bit ^ 1]].cnt > 0) {
            return get(x ^ (((ll)(bit ^ 1)) << pos), t[v].to[bit ^ 1], pos - 1, 0, cur + ((ll)(bit ^ 1) << pos));
        }
        if (t[t[v].to[bit]].cnt > 0) {
            return get(x ^ (((ll)(bit)) << pos), t[v].to[bit], pos - 1, 0, cur + ((ll)(bit) << pos));
        }
        
        return -1;
    }
    
    if (bit) {
        int res = -1;
        rep(j, 0, 2) {
            if (t[t[v].to[j]].cnt > 0) {
                maxi(res, get(x ^ (((ll)j) << pos), t[v].to[j], pos - 1, !j, cur + ((ll)(j) << pos)));
            }
        }
        return res;
    } else {
        if (t[t[v].to[0]].cnt > 0) {
            return get(x, t[v].to[0], pos - 1, 1, cur);
        }
        return -1;
    }
}

void solve(vector<int> b) {
    ptr = 1;
    memset(t, 0, sizeof t);
    int n = sz(b);
    vector<int> a(n);
    rep(i, 0, n) {
        a[n - 1] ^= b[i];
        add(b[i], 1);
    }
    vector<int> res;
    bool ok = 1;
    per(i, n - 2, 0) {
        int val = get(a[i + 1]);
        if (val == -1) {
            ok = 0;
            break;
        }
        a[i] = val;
        add(val ^ a[i + 1], -1);
        res.pb(val ^ a[i + 1]);
    }
    rep(i, 1, n) ok &= a[i - 1] < a[i];
    ok &= chk(a[0]);
    #ifdef LOCAL
    if (!ok) {
        cout << "BAD" << endl;
    }
    //~ cout << "OK" << endl;
    #else
    if (ok) {
        cout << "Yes\n";
        res.pb(a[0]);
        reverse(all(res));
        for (int i : res) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "No\n";
    }
    #endif
}

mt19937 rnd(42);

void run() {
    #ifdef LOCAL
    int n;
    cin >> n;
    rep(iter, 0, 10000) {
        vector<int> a(n);
        a[0] = rnd() % 100000;
        rep(i, 1, n) a[i] = a[i - 1] + 1 + rnd() % 100;
        vector<int> b(n);
        b[0] = a[0];
        rep(i, 1, n) b[i] = a[i - 1] ^ a[i];
        solve(b);
    }
    #else
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, 0, n) cin >> b[i];
    solve(b);
    #endif
}