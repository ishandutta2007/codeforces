#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

bool dp[MAXN + 1][2];
bool vis[MAXN + 1][2];

bool dfs(int nod, bool t, int p) {
    if(vis[nod][t])
        return dp[nod][t];
    int cnt = 0;
    for(auto it : g[nod]) {
        if(it != p && 2 * dfs(it, 0, nod) + dfs(it, 1, nod) > 1)
            cnt++;
    }
    vis[nod][t] = 1;
    if(cnt == 0) {
        return dp[nod][t] = (t == 0);
    }
    if((cnt + t) % 2 == 1) {
        for(auto it : g[nod]) {
            if(it != p && 2 * dp[it][0] + dp[it][1] == 3) {
                cnt--;
                break;
            }
        }
    }
    if((cnt + t) % 2 == 0) {
        dp[nod][t] = 1;
    }
    return dp[nod][t];
}

void solve(int nod, bool t, int p) {
    int cnt = 0;
    for(auto it : g[nod]) {
        if(it != p && 2 * dp[it][0] + dp[it][1] == 1) {
            solve(it, 1, nod);
        }
        if(it != p && 2 * dp[it][0] + dp[it][1] > 1) {
            cnt++;
        }
    }
    int id = -1;
    if((cnt + t) % 2 == 1) {
         for(auto it : g[nod]) {
            if(it != p && 2 * dp[it][0] + dp[it][1] == 3) {
                solve(it, 1, nod);
                id = it;
                cnt--;
                break;
            }
        }
    }
    cout << nod << "\n";
    for(auto it : g[nod]) {
        if(it != p && it != id && 2 * dp[it][0] + dp[it][1] != 1) {
            solve(it, 0, nod);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(x != 0) {
            g[x].push_back(i);
            g[i].push_back(x);
        }
    }
    if(1 - n & 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    dfs(1, 0, 0);
    solve(1, 0, 0);
    //cin.close();
    //cout.close();
    return 0;
}