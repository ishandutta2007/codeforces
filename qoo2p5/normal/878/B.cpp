#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
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

const int N = (int) 2e5 + 123;

template<typename T> struct Deque {
    int l, r;
    vector<T> q;
    
    Deque() {
        l = 0, r = 0;
        q.resize(4 * N + 100);
    }
    
    T& front() {
        return q[l];
    }
    
    void pop_front() {
        l++;
    }
    
    T& back() {
        return q[r - 1];
    }
    
    void pop_back() {
        r--;
    }
    
    int size() {
        return r - l;
    }
    
    void push_back(const T &x) {
        q[r++] = x;
    }
    
    void push_front(const T &x) {
        q[l--] = x;
    }
    
    void only_prefix() {
        if (size() > N) {
            r = l + N;
        }
        shift();
    }
    
    void only_suffix() {
        if (size() > N) {
            l = r - N;
        }
        shift();
    }
    
    void shift() {
        int len = size();
        rep(i, 0, len) {
            q[i] = q[l + i];
        }
        l = 0;
        r = len;
    }
};

int n, k, m;
int a[N];

struct Shit {
    bool divided;
    ll rest;
    Deque<pair<int, int>> l, r;
    
    Shit() {
        divided = 0;
        rest = 0;
    }
};

Shit init;

void convert() {
    Deque<pair<int, int>> q;
    ll cnt = 0;
    rep(i, 0, n) {
        cnt++;
        if (q.size() == 0) {
            q.push_back({a[i], 1});
        } else {
            if (q.back().first == a[i]) {
                q.back().second++;
            } else {
                q.push_back({a[i], 1});
            }
        }
        if (q.back().second >= k) {
            cnt -= k;
            q.pop_back();
        }
    }
    
    init.rest = cnt;
    init.l = q;
}

Shit merge(Shit a, Shit b) {
    Shit res;
    if (a.divided && b.divided) {
        res.rest = a.rest + b.rest;
        while (a.r.size() && b.l.size() && a.r.back().first == b.l.front().first) {
            int cntL = a.r.back().second;
            int cntR = b.l.front().second;
            assert(cntL < k && cntR < k);
            if (cntL + cntR < k) {
                a.r.back().second += cntR;
                b.l.pop_front();
                break;
            }
            a.r.pop_back();
            if (cntL + cntR == k) {
                b.l.pop_front();
            } else {
                b.l.front().second -= (k - cntL);
            }
            res.rest -= k;
        }
        res.divided = 1;
        res.l = a.l;
        res.r = b.r;
    } else if (a.divided) {
        res.rest = a.rest + b.rest;
        while (a.r.size() && b.l.size() && a.r.back().first == b.l.front().first) {
            int cntL = a.r.back().second;
            int cntR = b.l.front().second;
            assert(cntL < k && cntR < k);
            if (cntL + cntR < k) {
                a.r.back().second += cntR;
                b.l.pop_front();
                break;
            }
            a.r.pop_back();
            if (cntL + cntR == k) {
                b.l.pop_front();
            } else {
                b.l.front().second -= (k - cntL);
            }
            res.rest -= k;
        }
        res.divided = 1;
        res.l = a.l;
        while (b.l.size()) {
            a.r.push_back(b.l.front());
            b.l.pop_front();
        }
        res.r = a.r;
        res.r.only_suffix();
    } else if (b.divided) {
        res.rest = a.rest + b.rest;
        while (a.l.size() && b.l.size() && a.l.back().first == b.l.front().first) {
            int cntL = a.l.back().second;
            int cntR = b.l.front().second;
            assert(cntL < k && cntR < k);
            if (cntL + cntR < k) {
                a.l.back().second += cntR;
                b.l.pop_front();
                break;
            }
            a.l.pop_back();
            if (cntL + cntR == k) {
                b.l.pop_front();
            } else {
                b.l.front().second -= (k - cntL);
            }
            res.rest -= k;
        }
        res.divided = 1;
        res.r = b.r;
        while (b.l.size()) {
            a.l.push_back(b.l.front());
            b.l.pop_front();
        }
        res.l = a.l;
        res.l.only_prefix();
    } else {
        res.rest = a.rest + b.rest;
        while (a.l.size() && b.l.size() && a.l.back().first == b.l.front().first) {
            int cntL = a.l.back().second;
            int cntR = b.l.front().second;
            assert(cntL < k && cntR < k);
            if (cntL + cntR < k) {
                a.l.back().second += cntR;
                b.l.pop_front();
                break;
            }
            a.l.pop_back();
            if (cntL + cntR == k) {
                b.l.pop_front();
            } else {
                b.l.front().second -= (k - cntL);
            }
            res.rest -= k;
        }
        while (b.l.size()) {
            a.l.push_back(b.l.front());
            b.l.pop_front();
        }
        if (a.l.size() >= 2 * N) {
            auto l = a.l;
            auto r = a.l;
            l.only_prefix();
            r.only_suffix();
            res.divided = 1;
            res.l = l;
            res.r = r;
        } else {
            res.l = a.l;
        }
    }
    return res;
}

Shit solve(int x) {
    if (x == 1) {
        return init;
    }
    
    Shit tmp = solve(x / 2);
    Shit shit = merge(tmp, tmp);
    if (x & 1) {
        shit = merge(shit, init);
    }
    
    return shit;
}

void run() {
    cin >> n >> k >> m;
    rep(i, 0, n) {
        cin >> a[i];
    }
    
    convert();
    cout << solve(m).rest << "\n";
}