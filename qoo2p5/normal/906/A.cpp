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

int n;
vector<pair<string, string>> q;
bool can[256];

pair<bool, char> get() {
    int cnt = 0;
    char x = 'a';
    for (char a = 'a'; a <= 'z'; a++) {
        if (can[a]) {
            cnt++;
            x = a;
        }
    }
    return {cnt == 1, x};
}

void run() {
    fill(can, can + 256, 1);
    cin >> n;
    set<char> have;
    int ans = 0;
    char z = '0';
    rep(i, 0, n) {
        string t, w;
        cin >> t >> w;
        auto tmp = get();
        if (tmp.first) {
            z = tmp.second;
        }
        if (z != '0' && (t == "!" || (t == "?" && w[0] != z))) {
            ans++;
        }
        if (t == ".") {
            for (char c : w) {
                can[c] = 0;
            }
        } else if (t == "!") {
            have.clear();
            for (char c : w) {
                have.insert(c);
            }
            for (char a = 'a'; a <= 'z'; a++) {
                if (!have.count(a)) {
                    can[a] = 0;
                }
            }
        } else if (t == "?") {
            if (i == n - 1) {
                memset(can, 0, sizeof can);
                can[w[0]] = 1;
            } else {
                can[w[0]] = 0;
            }
        }
    }
    cout << ans << "\n";
}