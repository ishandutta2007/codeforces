#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 97

using namespace std;

const int MAXN = (int) 3e5;

vector <int> g[MAXN + 1];

string str;

char viz[MAXN + 1];
int top[MAXN + 1];
int sz;

void dfs(int nod) {
   viz[nod] = 1;
   for(auto it : g[nod]) {
        if(viz[it] == 0) {
            dfs(it);
        }
        else if(viz[it] == 1) {
            cout << -1;
            exit(0);
        }
   }
   viz[nod] = -1;
   top[++sz] = nod;
}

int dp[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> str;
    str = " " + str;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    for(i = 1; i <= n; i++) {
        if(viz[i] == 0)
            dfs(i);
    }
    int ans = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; i++) {
            for(auto it : g[top[i]]) {
                dp[top[i]] = max(dp[top[i]], dp[it]);
            }
            dp[top[i]] += (ch == str[top[i]]);
            ans = max(ans, dp[top[i]]);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}