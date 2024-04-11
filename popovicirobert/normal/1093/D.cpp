#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 3e5;

int pw[MAXN + 1];

vector <int> g[MAXN + 1];
bool vis[MAXN + 1], odd[MAXN + 1];
int fr[2];

void dfs(int nod, bool x) {
    vis[nod] = 1;
    odd[nod] = x;
    fr[x]++;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it, x ^ 1);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pw[0] = 1;
    for(i = 1; i <= MAXN; i++) {
        pw[i] = (pw[i - 1] * 2) % MOD;
    }
    cin >> t;
    while(t > 0) {
        t--;
        cin >> n >> m;
        for(i = 1; i <= n; i++) {
            g[i].clear();
        }
        for(i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(i = 1; i <= n; i++) {
            vis[i] = odd[i] = 0;
        }
        int cnt = 1;
        for(i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                fr[0] = fr[1] = 0;
                dfs(i, 1);
                cnt = (1LL * cnt * (pw[fr[1]] + pw[fr[0]])) % MOD;
            }
        }
        bool ans = 1;
        for(i = 1; i <= n; i++) {
            for(auto it : g[i]) {
                if(odd[i] == odd[it]) {
                    ans = 0;
                }
            }
        }
        cout << ans * cnt << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}