#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = ;

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


using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
ll dp[MAXN + 1];
int sz[MAXN + 1];

void dfs(int nod, int par) {
    sz[nod] = 1;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
            dp[nod] += dp[it];
            sz[nod] += sz[it];
        }
    }
    dp[nod] += sz[nod];
}

ll ans = 0;
int n;

void solve(int nod, int par, ll up) {

    ll sum = 0;
    for(auto it : g[nod]) {
        if(it != par) {
            sum += dp[it];
        }
    }

    ans = max(ans, sum + up + n);

    for(auto it : g[nod]) {
        if(it == par) {
            continue;
        }

        solve(it, nod, n - sz[it] + sum - dp[it] + up);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);
    solve(1, 0, 0);

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}