#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
int v[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
    if(x < 0)
        x += MOD;
}

int down[MAXN + 1][2];
bool vis[MAXN + 1];

void dfs(int nod) {
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it);
            for(int i = 0; i < 2; i++) {
                down[nod][i] += down[it][1 - i];
            }
        }
    }
    down[nod][1]++;
}

int n, ans = 0;

void solve(int nod, int cnt0, int cnt1) {
    int nr0 = 0, nr1 = 0;
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            nr0 += down[it][1];
            nr1 += down[it][0];
        }
    }
    int coef = (1LL * (nr1 + 1 - nr0 + MOD) * (n - nr0 - nr1)) % MOD;
    coef += (1LL * (cnt1 + 1 - cnt0 + MOD) * (nr0 + nr1 + 1)) % MOD;
    mod(coef);
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            coef += (1LL * down[it][0] * (nr0 + nr1 - down[it][0] - down[it][1])) % MOD;
            coef -= (1LL * down[it][1] * (nr0 + nr1 - down[it][0] - down[it][1])) % MOD;
            mod(coef);
            solve(it, cnt1 + nr1 - down[it][0] + 1, cnt0 + nr0 - down[it][1]);
        }
    }
    coef--;
    mod(coef);
    ans = (ans + 1LL * coef * v[nod]) % MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        mod(v[i]);
    }
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    memset(vis, 0, sizeof(vis));
    solve(1, 0, 0);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}