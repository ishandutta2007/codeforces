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
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <string> a(n), b(n);
    vector <int> fra(100), frb(100);

    auto get = [&](char x) -> int {
        return x - 'A';
    };

    for(i = 0; i < n; i++) {
        cin >> a[i];
        fra[get(a[i][0])]++;
    }
    for(i = 0; i < n; i++) {
        cin >> b[i];
        frb[get(b[i][0])]++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector <int> need(100);
    for(i = 0; i < 100; i++) {
        need[i] = min(fra[i], frb[i]);
    }

    vector <bool> vis(n);

    for(i = 0; i < n; i++) {
        int cha = get(a[i][0]);
        for(j = 0; j < n; j++) {
            if(vis[j] == 0) {
                int chb = get(b[j][0]);

                if(cha == chb) {
                    vis[j] = 1, frb[chb]--, need[cha]--;
                    cout << a[i] << " " << b[j];
                    break;
                }

                if(min(fra[chb], frb[chb] - 1) >= need[chb] && min(fra[cha] - 1, frb[cha]) >= need[cha]) {
                    vis[j] = 1, frb[chb]--;
                    cout << a[i] << " " << b[j];
                    break;
                }
            }
        }

        fra[cha]--;
        if(i != n - 1) {
            cout << ", ";
        }
    }

    return 0;
}