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

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1], aux[MAXN + 1];
int vis[MAXN + 1][2], from[MAXN + 1][2];

int in[MAXN + 1];

void dfs(int nod) {
    in[nod] = 1;
    for(auto it : g[nod]) {
        if(in[it] == 0) {
            dfs(it);
        }
        else if(in[it] == 1) {
            cout << "Draw";
            exit(0);
        }
    }
    in[nod] = 2;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        while(sz--) {
            int x;
            cin >> x;
            g[i].push_back(x), aux[x].push_back(i);
        }
    }

    int s; cin >> s;
    queue < pair <int, int> > Q;
    Q.push({s, 0}), vis[s][0] = 1;

    while(Q.size()) {
        int nod = Q.front().first;
        int par = Q.front().second;
        Q.pop();
        for(auto it : g[nod]) {
            if(vis[it][par ^ 1] == 0) {
                vis[it][par ^ 1] = 1;
                from[it][par ^ 1] = nod;
                Q.push({it, par ^ 1});
            }
        }
    }

    for(i = 1; i <= n; i++) {
        if(vis[i][1] && g[i].size() == 0) {
            cout << "Win\n";
            vector <int> sol;
            int cur = 1;
            while(i != s || cur != 0) {
                sol.push_back(i);
                i = from[i][cur];
                cur ^= 1;
            }
            sol.push_back(s);
            reverse(sol.begin(), sol.end());
            for(auto it : sol) {
                cout << it << " ";
            }
            return 0;
        }
    }

    dfs(s);
    cout << "Lose";

    return 0;
}