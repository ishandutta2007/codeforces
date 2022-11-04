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
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
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

struct Data {
    int x, y, z, t;
};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector <int> a(n + 1), b(n + 1), p(n + 1), q(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> x;
        p[x] = i, a[i] = i;
    }
    for(i = 1; i <= n; i++) {
        cin >> x;
        q[x] = i, b[i] = i;
    }
    vector <int> pa(n + 1), pb(n + 1);
    for(i = 1; i <= n; i++) {
        pa[i] = pb[i] = i;
    }
    vector <Data> sol;
    for(i = 1; i < n; i++) {
        if(a[i] == p[i] && b[i] == q[i]) continue;
        sol.push_back({pa[p[i]], i, i, pb[q[i]]});
        int x = a[i], y = p[i];
        swap(a[i], a[pa[p[i]]]), swap(pa[x], pa[y]);
        x = b[i], y = q[i];
        swap(b[i], b[pb[q[i]]]), swap(pb[x], pb[y]);
    }
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it.x << " " << it.y << " " << it.z << " " << it.t << "\n";
    }

    return 0;
}