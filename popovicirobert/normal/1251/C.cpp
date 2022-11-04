#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = ;

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
    int t, n, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        string str;

        cin >> str;
        n = str.size();
        for(auto &it : str) {
            it -= '0';
        }

        string sol;
        int l1 = 0, r1 = 0;
        while(r1 < n && str[r1] % 2 == str[l1] % 2) {
            r1++;
        }
        r1--;

        int l2 = 0, r2 = -1;
        while(1) {
            if(l1 > r1) {
                while(l1 < n && str[l1] % 2 == str[l2] % 2) {
                    l1++;
                }
                r1 = l1;
                while(r1 < n && str[r1] % 2 == str[l1] % 2) {
                    r1++;
                }
                r1--;
            }
            if(l2 > r2) {
                while(l2 < n && str[l2] % 2 == str[l1] % 2) {
                    l2++;
                }
                r2 = l2;
                while(r2 < n && str[r2] % 2 == str[l2] % 2) {
                    r2++;
                }
                r2--;
            }
            if(l1 == n || l2 == n) {
                break;
            }
            if(str[l1] <= str[l2]) {
                sol.push_back(str[l1++] + '0');
            }
            else {
                sol.push_back(str[l2++] + '0');
            }
        }

        for(i = l1; i < n; i++) {
            if(str[l1] % 2 == str[i] % 2)
                sol.push_back(str[i] + '0');
        }
        for(i = l2; i < n; i++) {
            if(str[l2] % 2 == str[i] % 2)
                sol.push_back(str[i] + '0');
        }
        cout << sol << "\n";
    }

    return 0;
}