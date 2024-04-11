#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 3005;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a  = (1LL * a * a) % MOD;
    }
    return ans;
}

vector <int> g[MAXN + 1];

int sp[MAXN + 1][MAXN + 2];
int n;

void dfs(int nod, int p) {
    for(auto it : g[nod]) {
        if(it != p)
            dfs(it, nod);
    }
    for(int i = 1; i <= n + 1; i++) {
        int prd = 1;
        for(auto it : g[nod]) {
            if(it != p)
                prd = (1LL * prd * sp[it][i]) % MOD;
        }
        sp[nod][i] = sp[nod][i - 1] + prd;
        mod(sp[nod][i]);
    }
}

int y[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, d;
    ios::sync_with_stdio(false);
    cin >> n >> d;
    for(i = 2; i <= n; i++) {
        int nod;
        cin >> nod;
        g[i].push_back(nod);
        g[nod].push_back(i);
    }
    dfs(1, 0);
    for(i = 1; i <= n + 1; i++) {
        y[i] = sp[1][i];
    }
    if(d <= n + 1)  {
        cout << y[d];
        return 0;
    }
    int a = 1, b = 1;
    for(i = 1; i <= n + 1; i++) {
        a = (1LL * a * (d - i)) % MOD;
    }
    for(i = 1; i <= n; i++) {
        b = (1LL * b * lgput(MOD - i, MOD - 2)) % MOD;
    }
    int ans = 0;
    for(i = 1; i <= n + 1; i++) {
        int cur = y[i];
        cur = (1LL * cur * a) % MOD;
        cur = (1LL * cur * lgput(d - i, MOD - 2)) % MOD;
        cur = (1LL * cur * b) % MOD;
        ans += cur;
        mod(ans);
        b = (1LL * b * (MOD - (n - i + 1))) % MOD;
        b = (1LL * b * lgput(i, MOD - 2)) % MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}