#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


const int MOD = 998244353;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

int dp0[MAXN + 1]; // nod nu e colorat
int dp1[MAXN + 1][2];
// dp1[nod][0] = nod e colorat si are un fiu colorat;
// dp1[nod][1] = nod e colorat si are mai multi fii colorati;

void dfs(int nod) {
    if(g[nod].size() == 0) {
        dp1[nod][1] = 1;
        return ;
    }

    dp0[nod] = 1;

    for(auto it : g[nod]) {

        dfs(it);

        vector <ll> aux(2);
        aux[0] = dp1[nod][0], aux[1] = dp1[nod][1];

        dp1[nod][0] = (1LL * aux[0] * (dp0[it] + dp1[it][1]) + 1LL * dp0[nod] * (dp1[it][0] + dp1[it][1])) % MOD;
        dp1[nod][1] = (1LL * aux[1] * (dp0[it] + dp1[it][0] + 2LL * dp1[it][1]) + 1LL * aux[0] * (dp1[it][0] + dp1[it][1])) % MOD;

        mul(dp0[nod], dp0[it] + dp1[it][1]);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }

    dfs(1);

    cout << (dp0[1] + dp1[1][1]) % MOD;

    return 0;
}