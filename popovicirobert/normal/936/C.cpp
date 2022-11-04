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

vector <int> sol;

inline string get(string cur, int len) {
    sol.push_back(len);
    int n = cur.size();
    string aux;
    for(int i = n - 1; i >= n - len; i--) {
        aux += cur[i];
    }
    return aux + cur.substr(0, n - len);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s, t;
    cin >> n >> s >> t;

    string a = s, b = t;
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    if(a != b) { cout << -1; return 0; }

    for(int len = 0; len < n; len++) {
        int x = 0;
        while(s[x] != t[len]) x++;
        s = get(s, n - x - 1);
        s = get(s, 1);
        s = get(s, n);
    }

    cout << sol.size() << "\n";
    for(auto it : sol) cout << it << " ";

    return 0;
}