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

const int N = (int) 1e5 + 123;
const int K = 22;

int n, k;
int a[N];
ll dp[N][K];
ll cnt[N];

ll f(int i) {
    return cnt[i] * (cnt[i] - 1) / 2;
}

struct Q {
    int l, r, bl, br;
};

vector<Q> q, nq;

void solve(int level) {
    while (sz(q)) {
        memset(cnt, 0, sizeof cnt);
        int cur_l = 1;
        int cur_r = 1;
        cnt[a[1]]++;
        ll cur_f = 0;
        
        for (Q &t : q) {
            assert(t.l < t.r);
            int mid = (t.l + t.r) / 2;
            while (cur_r < mid) {
                cur_r++;
                cur_f -= f(a[cur_r]);
                cnt[a[cur_r]]++;
                cur_f += f(a[cur_r]);
            }
            assert(cur_r == mid);
            int opt = -1;
            
            rep(i, t.bl, min(mid, t.br) + 1) {
                while (cur_l < i) {
                    cur_f -= f(a[cur_l]);
                    cnt[a[cur_l]]--;
                    cur_f += f(a[cur_l]);
                    cur_l++;
                }
                assert(cur_l == i);
                
                if (mini(dp[mid][level], dp[i - 1][level - 1] + cur_f)) {
                    opt = i;
                }
            }
            
            if (t.l < mid && opt != -1) nq.push_back({t.l, mid, t.bl, opt});
            if (mid + 1 < t.r) nq.push_back({mid + 1, t.r, max(opt, t.bl), t.br});
        }
        
        q = nq;
        nq.clear();
    }
}

void run() {
    rep(i, 0, N) {
        rep(j, 0, K) {
            dp[i][j] = LINF;
        }
    }
    
    cin >> n >> k;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    
    dp[0][0] = 0;
    rep(j, 1, k + 1) {
        q.clear();
        q.push_back({1, n + 1, 1, n});
        solve(j);
    }
    
    cout << dp[n][k] << "\n";
}