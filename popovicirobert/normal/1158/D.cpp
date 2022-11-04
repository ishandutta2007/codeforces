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



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector <ll> x(n), y(n);
    for(i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    auto det = [&](int a, int b, int c) {
        return x[a] * y[b] + x[b] * y[c] + x[c] * y[a] - x[b] * y[a] - x[c] * y[b] - x[a] * y[c];
    };

    int id1 = 0;
    for(i = 1; i < n; i++) {
        if(x[id1] > x[i] || (x[id1] == x[i] && y[id1] > y[i])) {
            id1 = i;
        }
    }

    vector <int> sol = {id1};
    string str; cin >> str;
    vector <bool> vis(n); vis[id1] = 1;

    for(i = 0; i < n - 2; i++) {
        vector <int> cur;
        for(j = 0; j < n; j++) {
            if(vis[j] == 0) cur.push_back(j);
        }
        int id2 = -1;
        for(j = 0; j < n; j++) {
            if(vis[j]) continue;
            if(id2 == -1) { id2 = j; continue; }
            ll cur = det(id1, id2, j);
            if(str[i] == 'L' && cur < 0) id2 = j;
            if(str[i] == 'R' && cur > 0) id2 = j;
        }
        sol.push_back(id2), vis[id2] = 1, id1 = id2;
    }

    for(i = 0; i < n; i++) {
        if(vis[i] == 0) sol.push_back(i);
    }
    for(auto it : sol) {
        cout << it + 1 << " ";
    }

    return 0;
}