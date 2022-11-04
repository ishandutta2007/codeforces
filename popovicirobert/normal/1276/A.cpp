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



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        string str;
        cin >> str;

        n = str.size();
        str = " " + str;

        vector < vector <int> > dp(n + 1, vector <int>(7, 1e9));
        vector < vector <int> > from(n + 1, vector <int>(7));

        string pat[7] = {"", "o", "on", "one", "t", "tw", "two"};

        dp[0][0] = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < 7; j++) {
                if(dp[i][j] == 1e9 || pat[j].size() == 3) continue;

                if(dp[i + 1][j] > dp[i][j] + 1) {
                    dp[i + 1][j] = dp[i][j] + 1;
                    from[i + 1][j] = j;
                }

                char ch = str[i + 1];
                string cur = pat[j];
                cur.push_back(ch);

                bool ok = 1;
                for(int p = 0; p < 7; p++) {
                    if(cur == pat[p]) {
                        if(dp[i + 1][p] > dp[i][j]) {
                            dp[i + 1][p] = dp[i][j];
                            from[i + 1][p] = j;
                        }
                        ok = 0;
                    }
                }

                if(ok) {
                    int id = 0;
                    if(ch == 'o') {
                        id = 1;
                    }
                    if(ch == 't') {
                        id = 4;
                    }
                    if(dp[i + 1][id] > dp[i][j]) {
                        dp[i + 1][id] = dp[i][j];
                        from[i + 1][id] = j;
                    }
                }
            }
        }

        //cerr << dp[3][1] << " ";

        int ans = 1e9, l, c;
        for(i = 0; i < 7; i++) {
            if(pat[i].size() < 3) {
                if(ans > dp[n][i]) {
                    ans = dp[n][i];
                    l = n, c = i;
                }
            }
        }
        cout << ans << "\n";

        while(l > 0 || c > 0) {
            if(dp[l][c] > dp[l - 1][from[l][c]]) {
                cout << l << " ";
            }
            c = from[l][c], l--;
        }
        cout << "\n";
    }

    return 0;
}