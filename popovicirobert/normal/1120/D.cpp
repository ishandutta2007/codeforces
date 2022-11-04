#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];
int c[MAXN + 1];
ll dp[MAXN + 1][2];

void dfs(int nod, int par) {
    ll mn = INF;
    int son = 0;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
            dp[nod][0] += dp[it][1];
            dp[nod][1] += dp[it][1];
            mn = min(mn, dp[it][0] - dp[it][1]);
            son++;
        }
    }
    if(son == 0) {
        dp[nod][0] = 0;
        dp[nod][1] = c[nod];
    }
    else {
        dp[nod][0] += mn;
        dp[nod][1] = min(dp[nod][1], dp[nod][0] + c[nod]);
    }
    //cerr << nod << " " << dp[nod][0] << " " << dp[nod][1] << "\n";
}

bool ok[MAXN + 1][2];

void solve(int nod, int par, vector <int> &sol) {
    ll mn = INF, s = 0;
    int son = 0, cnt = 0;
    for(auto it : g[nod]) {
        if(it != par) {
            s += dp[it][1];
            mn = min(mn, dp[it][0] - dp[it][1]);
            son++;
        }
    }
    for(auto it : g[nod]) {
        if(it != par) {
            if(mn == dp[it][0] - dp[it][1]) {
                cnt++;
            }
        }
    }
    //cerr << nod << " " << par << " " << son << "\n";
    if(son > 0) {
        if(ok[nod][1]) {
            if(dp[nod][1] == s) {
                for(auto it : g[nod]) {
                    if(it != par) {
                        ok[it][1] = 1;
                    }
                }
            }
            if(dp[nod][1] == s + mn + c[nod]) {
                sol.push_back(nod);
                for(auto it : g[nod]) {
                    if(it != par) {
                        if(mn == dp[it][0] - dp[it][1]) {
                            ok[it][0] = 1;
                        }
                        if(mn != dp[it][0] - dp[it][1] || cnt > 1) {
                            ok[it][1] = 1;
                        }
                    }
                }
            }
        }
        if(ok[nod][0]) {
            for(auto it : g[nod]) {
                if(it != par) {
                    if(mn == dp[it][0] - dp[it][1]) {
                        ok[it][0] = 1;
                    }
                    if(mn != dp[it][0] - dp[it][1] || cnt > 1) {
                        ok[it][1] = 1;
                    }
                }
            }
        }
    }
    else {
        if(ok[nod][1]) {
            sol.push_back(nod);
        }
    }
    for(auto it : g[nod]) {
        if(it != par) {
            solve(it, nod, sol);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    dfs(1, 0);
    vector <int> sol;
    ok[1][1] = 1;
    solve(1, 0, sol);
    cout << dp[1][1] << " " << sol.size() << "\n";
    sort(sol.begin(), sol.end());
    for(auto it : sol) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}