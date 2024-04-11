#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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

const int MAXN = (int) 3e5;

struct Query {
    int r;
    int pos;
    bool operator <(const Query &other) const {
        return r < other.r;
    }
};

int arr[MAXN + 1];
vector <Query> qry[MAXN + 1];

int dp[MAXN + 1];
bool sol[MAXN + 1];

void divide(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) / 2, i, j;

    for(j = 0; j < 20; j++) {
        int last = (1 << j);
        for(i = mid; i >= l; i--) {
            dp[i] = last;
            if(dp[i] & arr[i]) {
                dp[i] |= arr[i];
            }
            last = dp[i];
        }
        last = (1 << j);
        for(i = mid + 1; i <= r; i++) {
            dp[i] = last;
            if(dp[i] & arr[i]) {
                dp[i] |= arr[i];
            }
            last = dp[i];
        }
        for(i = mid; i >= l; i--) {
            for(int p = (int) qry[i].size() - 1; p >= 0 && qry[i][p].r > mid; p--) {
                if((dp[i] & arr[i]) && (dp[qry[i][p].r] & arr[qry[i][p].r])) {
                    sol[qry[i][p].pos] = 1;
                }
            }
        }
    }

    for(i = l; i <= mid; i++) {
        while(qry[i].size() && qry[i].back().r > mid) {
            qry[i].pop_back();
        }
    }

    divide(l, mid); divide(mid + 1, r);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        qry[l].push_back({r, i});
    }
    for(i = 1; i <= n; i++) {
        sort(qry[i].begin(), qry[i].end());
    }

    divide(1, n);

    for(i = 1; i <= q; i++) {
        cout << (sol[i] ? "Shi\n" : "Fou\n");
    }

    return 0;
}