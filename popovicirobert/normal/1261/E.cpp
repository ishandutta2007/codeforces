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
#ifdef LOCAL
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector <string> str(n + 2);
    vector <int> r(n + 2, n + 1);

    for(int lin = 1; lin <= n; lin++) {

        int cnt0 = n + 1 - a[lin], cnt1 = a[lin];

        i = 1;
        while(i <= n + 1) {
            if(i == r[i]) {
                i++;
                continue;
            }
            else {
                int j = i, aux = r[i];
                while(j < r[i] && cnt0 > 0) {
                    str[j++].push_back('0');
                    cnt0--;
                }

                for(int p = i; p < j; p++) {
                    r[p] = j - 1;
                }

                while(j <= aux) {
                    r[j] = aux;
                    str[j++].push_back('1');
                    cnt1--;
                }

                break;
            }
        }

        for(i = 1; i <= n + 1; i++) {
            if(str[i].size() < lin) {
                if(cnt0) {
                    cnt0--;
                    str[i].push_back('0');
                }
                else {
                    cnt1--;
                    str[i].push_back('1');
                }
            }
        }
    }

    cout << n + 1 << "\n";
    for(i = 1; i <= n + 1; i++) {
        cout << str[i] << "\n";
    }

    return 0;
}