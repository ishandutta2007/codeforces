#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


const int MOD = 998244353;

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

const int MAXN = 1000;

int dp[MAXN + 1][MAXN + 1], sp[MAXN + 1][MAXN + 1];

inline int get(int l, int r) {
    if(l > r) return 1;
    return dp[l][r];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector <int> arr(1);
    int prv = 0;

    while(m--) {
        int x;
        cin >> x;

        if(prv != x) {
            arr.push_back(x);
        }
        prv = x;
    }

    if((int) arr.size() - 1 > 2 * n) {
        cout << 0;
        return 0;
    }

    vector <int> first(n + 1), last(n + 1);
    n = (int) arr.size() - 1;

    for(i = 1; i <= n; i++) {
        if(first[arr[i]] == 0) {
            first[arr[i]] = i;
        }
        last[arr[i]] = i;
    }

    for(i = 1; i <= n; i++) {
        if(first[arr[i]] == last[arr[i]]) {
            dp[i][i] = 1;
            sp[i][i] = 2;
        }
        sp[i + 1][i] = 1;
    }

    for(int len = 1; len < n; len++) {
        for(int l = 1; l + len <= n; l++) {
            int r = l + len, mn = 1e9, a = -1, b;

            bool flag = 1;
            for(int k = l; k <= r; k++) {
                if(first[arr[k]] < l || last[arr[k]] > r) {
                    flag = 0;
                }
                if(mn > arr[k]) {
                    mn = arr[k];
                    a = b = k;
                }
                else if(mn == arr[k]) {
                    b = k;
                }
            }

            if(flag == 0) {
                continue;
            }

            int prv = -1, prd = 1;
            for(int k = l; k <= r; k++) {
                if(arr[k] == mn) {
                    if(prv != -1) {
                        mul(prd, get(prv + 1, k - 1));
                    }
                    prv = k;
                }
            }

            for(int k = a; k >= l; k--) {
                int cur = prd;
                mul(cur, get(l, k - 1));
                mul(cur, get(k, a - 1));
                mul(cur, sp[b + 1][r]);
                add(dp[l][r], cur);
            }

            for(int k = l - 1; k <= r; k++) {
                add(sp[l][r], (1LL * get(l, k) * get(k + 1, r)) % MOD);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}