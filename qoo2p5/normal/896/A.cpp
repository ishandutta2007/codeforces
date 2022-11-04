#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int INF = (int) 1e9 + 1e6;
const ll LINF = (ll) 1e18 + 1e9;
const ld EPS = (ld) 1e-10;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (auto i = f; i < t; ++(i))
#define per(i, f, t) for (auto i = (f); i >= (t); --(i))

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

const int N = (int) 1e5 + 123;

string init = "What are you doing at the end of the world? Are you busy? Will you save us?";
string pre = "What are you doing while sending \"";
string mid = "\"? Are you busy? Will you send \"";
string suff = "\"?";

ll len[N];

char solve(int i, ll k) {
    if (len[i] < k) {
        return '.';
    }
    if (i == 0) {
        return init[k - 1];
    }
    if (sz(pre) >= k) {
        return pre[k - 1];
    }
    if (sz(pre) + len[i - 1] >= k) {
        return solve(i - 1, k - sz(pre));
    }
    if (sz(pre) + len[i - 1] + sz(mid) >= k) {
        return mid[k - sz(pre) - len[i - 1] - 1];
    }
    if (sz(pre) + len[i - 1] + sz(mid) + len[i - 1] >= k) {
        return solve(i - 1, k - sz(pre) - len[i - 1] - sz(mid));
    }
    return suff[k - sz(pre) - len[i - 1] - sz(mid) - len[i - 1] - 1];
}

void run() {
    len[0] = sz(init);
    rep(i, 1, N) {
        len[i] = sz(pre) + len[i - 1] + sz(mid) + len[i - 1] + sz(suff);
        mini(len[i], LINF);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        ll k;
        cin >> n >> k;
        cout << solve(n, k);
    }
    cout << "\n";
}