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

const int MAXN = (int) 1e5;

set <int> g[MAXN + 1];
int dep[MAXN + 1];

void dfs(int nod) {
    dep[nod] = 1;
    for(auto it : g[nod]) {
        dfs(it);
        dep[nod] = max(dep[nod], dep[it] + 1);
    }
}

vector <int> ord, sol;

void solve(int nod) {
    ord.push_back(nod);

    if(g[nod].empty()) {
        return ;
    }
    if(g[nod].size() == 1) {
        solve(*g[nod].begin());
        return ;
    }

    vector <int> ord;
    for(auto it : g[nod]) {
        ord.push_back(it);
    }

    sort(ord.begin(), ord.end(), [&](const int &x, const int &y) {
                if(dep[x] == dep[y]) return x < y;
                return dep[x] > dep[y];
         });

    int last = ord[0];
    for(auto it : ord) {
        if(it != last) {
            g[it].insert(last);
            dep[it] = dep[last] + 1;
            sol.push_back(last);
            last = it;
        }
    }

    solve(last);
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i < n; i++) {
        int par;
        cin >> par;
        g[par].insert(i);
    }

    dfs(0);
    solve(0);

    for(auto it : ord) {
        cout << it << " ";
    }
    cout << "\n" << sol.size() << "\n";
    reverse(sol.begin(), sol.end());
    for(auto it : sol) {
        cout << it << " ";
    }

    return 0;
}