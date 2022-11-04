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

#define len first
#define id second

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector < pair <int, int> > d(n);
    for(i = 0; i < n; i++) {
        cin >> d[i].len;
        d[i].id = i;
    }

    sort(d.rbegin(), d.rend());

    vector <int> nodes;
    vector < pair <int, int> > sol;

    nodes.push_back(d[0].id * 2);
    for(i = 1; i <= d[0].len - 1; i++) {
        nodes.push_back(d[i].id * 2);
    }
    nodes.push_back(d[0].id * 2 + 1);

    for(i = 1; i <= d[0].len - 1; i++) {
        if(i + d[i].len - 1 >= (int) nodes.size() - 1) {
            nodes.push_back(d[i].id * 2 + 1);
        }
        else {
            sol.push_back({nodes[i + d[i].len - 1], d[i].id * 2 + 1});
        }
    }

    for(i = d[0].len; i < n; i++) {
        sol.push_back({d[0].id * 2, d[i].id * 2});
        if(d[i].len == 1) {
            sol.push_back({d[i].id * 2, d[i].id * 2 + 1});
        }
        else {
            sol.push_back({nodes[d[i].len - 2], d[i].id * 2 + 1});
        }
    }

    for(i = 0; i + 1 < nodes.size(); i++) {
        sol.push_back({nodes[i], nodes[i + 1]});
    }

    for(auto it : sol) {
        cout << it.first + 1 << " " << it.second + 1 << "\n";
    }


    return 0;
}