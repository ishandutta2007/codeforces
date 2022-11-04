#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = (int) ;

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

const int MAXN = 25;
const int MAXV = 50000;

bitset <MAXN * MAXV + 1> dp[2 * MAXN][MAXN + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> arr(2 * n);
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(i = n; i < 2 * n; i++) {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    vector < vector <int> > sol(2, vector <int>(n));
    sol[0][0] = arr[2 * n - 1];
    sol[1][n - 1] = arr[2 * n - 2];

    arr.resize(2 * n - 2);
    int sz = arr.size(), tot = 0;

    for(auto it : arr) {
        tot += it;
    }

    dp[0][0][0] = 1;
    dp[0][1][arr[0]] = 1;

    for(i = 0; i + 1 < sz; i++) {
        for(j = 0; j <= min(i + 1, n); j++) {
            dp[i + 1][j] = (dp[i + 1][j] | dp[i][j]);
            if(j < n) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] | (dp[i][j] << arr[i + 1]));
            }
        }
    }

    int s, mn = 1e9;
    for(int sum = 0; sum <= tot; sum++) {
        int cur = max(sum, tot - sum);
        if(dp[sz - 1][n - 1][sum] && cur <= mn) {
            mn = cur;
            s = sum;
        }
    }

    //cerr << s + sol[0][0] << " " << tot - s + sol[1][n - 1] << "\n";

    vector <bool> vis(sz);
    i = sz - 1, j = n - 1;

    while(i >= 0) {
        //cerr << i << " " << j << " " << s << " " << arr[i] << " " << dp[i][j][s] << "\n";
        if(i == 0) {
            vis[i] = 1 - j;
        }
        else {
            if(dp[i - 1][j][s]) {
                vis[i] = 1;
            }
            else {
                vis[i] = 0;
                j--;
                s -= arr[i];
            }
        }
        i--;
    }

    int id = 1;
    for(i = 0; i < sz; i++) {
        if(vis[i] == 0) {
            sol[0][id++] = arr[i];
        }
    }
    id = n - 1;
    for(i = 0; i < sz; i++) {
        if(vis[i]) {
            sol[1][--id] = arr[i];
        }
    }

    sort(sol[0].begin(), sol[0].end());
    sort(sol[1].rbegin(), sol[1].rend());

    for(i = 0; i < 2; i++) {
        for(j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}