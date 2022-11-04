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


int fr[11][62][62];
int ways[62][62][62];

inline int encode(char ch) {
    if(ch >= 'a' && ch <= 'z') return ch - 'a';
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
    return ch - '0' + 52;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <string> all;
    for(i = 1; i <= n; i++) {
        string str;
        cin >> str;
        all.push_back(str);
        reverse(str.begin(), str.end());
        all.push_back(str);
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    for(auto &it : all) {
        fr[it.size()][encode(it[0])][encode(it.back())]++;
    }

    vector <int> fact(5, 1);
    fact[2] = 2;
    fact[3] = 6;
    fact[4] = 24;

    int ans = 0;

    for(int len = 3; len <= 10; len++) {
        for(int ch2 = 0; ch2 < 62; ch2++) {
            for(int ch3 = ch2; ch3 < 62; ch3++) {
                for(int ch4 = ch3; ch4 < 62; ch4++) {
                    ways[ch2][ch3][ch4] = 0;
                    for(int ch1 = 0; ch1 < 62; ch1++) {
                        add(ways[ch2][ch3][ch4], (1LL * fr[len][ch1][ch2] * fr[len][ch1][ch3] * fr[len][ch1][ch4]) % MOD);
                    }
                }
            }
        }

        for(int ch1 = 0; ch1 < 62; ch1++) {
            for(int ch2 = ch1; ch2 < 62; ch2++) {
                for(int ch3 = ch2; ch3 < 62; ch3++) {
                    for(int ch4 = ch3; ch4 < 62; ch4++) {

                        int cnt = 24, num = 1;
                        if(ch2 != ch1) {
                            cnt /= fact[num], num = 1;
                        }
                        else {
                            num++;
                        }

                        if(ch3 != ch2) {
                            cnt /= fact[num], num = 1;
                        }
                        else {
                            num++;
                        }

                        if(ch4 != ch3) {
                            cnt /= fact[num], num = 1;
                        }
                        else {
                            num++;
                        }

                        cnt /= fact[num];

                        int cur = (1LL * ways[ch1][ch2][ch3] * ways[ch1][ch2][ch4]) % MOD;
                        mul(cur, ways[ch1][ch3][ch4]);
                        mul(cur, ways[ch2][ch3][ch4]);
                        mul(cur, cnt);
                        add(ans, cur);

                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}