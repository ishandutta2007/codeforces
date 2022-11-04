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
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> x(n), y(n);
    for(i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    while(true) {
        int xmin = *min_element(x.begin(), x.end());
        int ymin = *min_element(y.begin(), y.end());

        int cnt[] = {0, 0};
        for(i = 0; i < n; i++) {
            x[i] -= xmin;
            y[i] -= ymin;
            cnt[(x[i] + y[i]) % 2]++;
        }

        if(cnt[0] && cnt[1]) {
            vector <int> sol;
            for(i = 0; i < n; i++) {
                if((x[i] + y[i]) % 2) {
                    sol.push_back(i);
                }
            }
            cout << sol.size() << "\n";
            for(auto it : sol) {
                cout << it + 1 << " ";
            }
            return 0;
        }

        vector <int> sol;
        for(i = 0; i < n; i++) {
            if(x[i] & 1) {
                sol.push_back(i);
            }
        }

        if(sol.size()) {
            cout << sol.size() << "\n";
            for(auto it : sol) {
                cout << it + 1 << " ";
            }
            return 0;
        }

        for(i = 0; i < n; i++) {
            x[i] /= 2;
            y[i] /= 2;
        }
    }

    return 0;
}