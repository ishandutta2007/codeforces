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

const int MAXN = (int) 1e6 + 5;

ll a[MAXN + 1], divi[MAXN + 1];
int fr[MAXN + 1];
bool vis[MAXN + 1];

int main() {
#ifdef HOME
    //ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
    int i, n;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    double start = clock();

    srand(time(0));

    //cin >> n;
    scanf("%d" ,&n);
    for(i = 0; i < n; i++) {
        //cin >> a[i];
        scanf("%lld" ,&a[i]);
    }

    auto myrand = [&]() {
        return (1LL * (1LL * rand() << 15) ^ rand()) % n;
    };


    ll ans = 0;

    for(int t = 0; t < 20 && t < n; t++) {
        int cur = myrand() % n;
        while(vis[cur]) {
            cur = myrand() % n;
        }
        vis[cur] = 1;

        int sz = 0;
        for(int j = 1; 1LL * j * j <= a[cur]; j++) {
            if(a[cur] % j == 0) {
                divi[sz++] = j;
                if(1LL * j * j < a[cur]) {
                    divi[sz++] = a[cur] / j;
                }
            }
        }
        sort(divi, divi + sz);

        for(i = 0; i < n; i++) {
            int id = lower_bound(divi, divi + sz, __gcd(a[i], a[cur])) - divi;
            fr[id]++;
        }

        for(i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                if(divi[j] % divi[i] == 0) {
                    fr[i] += fr[j];
                }
            }
            if(2 * fr[i] >= n) {
                ans = max(ans, divi[i]);
            }
            fr[i] = 0;
        }

        if(1.0 * (clock() - start) / CLOCKS_PER_SEC >= 3.0) {
            cout << ans;
            return 0;
        }
    }

    cout << ans;

    return 0;
}