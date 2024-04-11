#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



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
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(n);
    int cnt0 = 0;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        cnt0 += (a[i] == 0);
    }

    if(n == 1) {
        if(a[0] % 2) {
            cout << "sjfnb";
        }
        else {
            cout << "cslnb";
        }
        return 0;
    }
    if(cnt0 >= 2) {
        cout << "cslnb";
        return 0;
    }

    sort(a.begin(), a.end());
    int cnt = 0;
    for(i = 0; i + 1 < n; i++) {
        if(a[i] == a[i + 1]) {
            cnt++;
        }
    }

    if(cnt >= 2) {
        cout << "cslnb";
        return 0;
    }

    for(i = 0; i < n; i++) {
        if(a[i] == a[i + 1]) {
            if(i > 0 && a[i] == a[i - 1] + 1) {
                cout << "cslnb";
                return 0;
            }
            a[i]--;
        }
    }

    int ans = (1LL * a[0] * n) % 2;
    for(i = 1; i < n; i++) {
        ans = (ans + 1LL * (a[i] - a[i - 1] - 1) * (n - i)) % 2;
    }

    cnt = (cnt == 1);

    if((ans ^ cnt) & 1) {
        cout << "sjfnb";
    }
    else {
        cout << "cslnb";
    }

    return 0;
}