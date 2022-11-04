#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



/*const int MOD = ;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}*/

/*int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}*/

using namespace std;

#define a first
#define b second

const int MAXN = (int) 5e5;
const ll INF = 1e18;

pair <ll, ll> deq[MAXN + 1];
int bg, en;

inline double inter(pair <ll, ll> l1, pair <ll, ll> l2) {
    if(l1.a == l2.a) return INF;
    return 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
}

inline void update(ll a, ll b) {
    while(en > bg && inter(deq[en - 1], deq[en]) - inter(deq[en - 1], {a, b}) >= 0) {
        en--;
    }
    deq[++en] = {a, b};
}

inline ll get(pair <ll, ll> l, ll x) {
    return 1LL * l.a * x + l.b;
}

inline ll query(ll x) {
    if(bg > en) {
        return INF;
    }
    int res = bg - 1;
    for(int step = 1 << 18; step; step >>= 1) {
        if(res + step < en && get(deq[res + step + 1], x) <= get(deq[res + step], x)) {
            res += step;
        }
    }
    return get(deq[res + 1], x);
}

vector <int> g[MAXN + 1];
ll dp[MAXN + 1], mn = INF;
int sz[MAXN + 1], n;

void dfs(int nod, int par) {
    sz[nod] = 1;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
            sz[nod] += sz[it];
        }
    }
    if(sz[nod] == 1) { dp[nod] = 1; return ; }

    vector <int> ord; dp[nod] = INF;
    for(auto it : g[nod]) {
        if(it != par) {
            dp[nod] = min(dp[nod], dp[it] + 1LL * (sz[nod] - sz[it]) * (sz[nod] - sz[it]));
            ord.push_back(it);
        }
    }
    sort(ord.begin(), ord.end(), [&](const int &a, const int &b) {
            if(sz[a] == sz[b]) return dp[a] + 1LL * sz[a] * sz[a] - 2LL * n * sz[a] < dp[b] + 1LL * sz[b] * sz[b] - 2LL * n * sz[b];
            return sz[a] > sz[b];
        });
    bg = 0, en = -1;
    for(auto it : ord) {
        ll ct = dp[it] + 1LL * n * n + 1LL * sz[it] * sz[it] - 2LL * n * sz[it];
        mn = min(mn, query(sz[it]) + ct);
        ll a = 2 * sz[it];
        ll b = dp[it] + 1LL * sz[it] * sz[it] - 2LL * n * sz[it];
        update(a, b);
    }
}


int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    if(n == 2) {
        cout << 2;
        return 0;
    }

    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int root;
    for(i = 1; i <= n; i++) {
        if(g[i].size() > 1) {
            root = i;
        }
    }
    dfs(root, 0);

    cout << 1LL * n * (n - 1) - (mn - n) / 2;

    return 0;
}