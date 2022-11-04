#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 1
const int MOD = (int) 1e9 + 7;

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
}
#endif

#if 0
int fact[], invfact[];

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
}
#endif

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];

ll x[MAXN + 1][20];
int anc[MAXN + 1][20];

void dfs(int nod, int par) {
    anc[nod][0] = par;
    for(int bit = 1; bit < 20; bit++) {
        anc[nod][bit] = anc[anc[nod][bit - 1]][bit - 1];
        x[nod][bit] = __gcd(x[nod][bit - 1], x[anc[nod][bit - 1]][bit - 1]);
    }
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
        }
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i <= n; i++) {
        cin >> x[i][0];
    }
    for(i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);

    int ans = 0;

    for(i = 1; i <= n; i++) {
        ll cur = x[i][0];
        int nod = i;

        while(nod != 1) {
            int aux = nod, dst = 0;
            ll val = cur;

            for(int bit = 19; bit >= 0; bit--) {
                if(anc[aux][bit] != 0 && __gcd(x[aux][bit], val) == val) {
                    aux = anc[aux][bit];
                    dst += (1 << bit);
                }
            }

            ans = (ans + 1LL * val * dst) % MOD;
            nod = aux;
            cur = __gcd(val, x[nod][0]);
        }
        ans = (ans + cur) % MOD;
    }

    cout << ans;

    return 0;
}