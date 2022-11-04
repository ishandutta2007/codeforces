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

const ll T = 12 * 3600;

bool ok(ll x, ll l, ll r) {
    return (l < x && x < r) || (l < x + T && x + T < r);
}

void run() {
    ll h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    h %= 12;
    t1 %= 12;
    t2 %= 12;
    ll secs_cur = s + m * 60 + h * 60 * 60;
    ll p1 = secs_cur % T;
    ll p2 = (12 * secs_cur) % T;
    ll p3 = (12 * 60 * secs_cur) % T;
    vector<ll> p = {p1, p2, p3};
    sort(all(p));
    p.push_back(p.front() + T);
    
    ll from = (t1 * 60 * 60) % T;
    ll to = (t2 * 60 * 60) % T;
    rep(i, 0, 3) {
        ll l = p[i];
        ll r = p[i + 1];
        if (ok(from, l, r) && ok(to, l, r)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}