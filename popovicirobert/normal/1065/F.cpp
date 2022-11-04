#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

vector <int> g[MAXN + 1];
pair <int, int> arr[MAXN + 1];
int k;

void dfs(int nod, int par, int lvl) {
    arr[nod] = {2 * MAXN, 0};
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod, lvl + 1);
            if(lvl >= arr[it].first) {
                arr[nod].first = min(arr[nod].first, arr[it].first);
                arr[nod].second += arr[it].second;
            }
        }
    }
    if(g[nod].size() == 0) {
        arr[nod] = {lvl - k, 1};
    }
}

int dp[MAXN + 1];

void dfs1(int nod, int par, int lvl) {
    dp[nod] = (g[nod].size() == 0);
    for(auto it : g[nod]) {
        if(it != par) {
            dfs1(it, nod, lvl + 1);
            int cur = arr[nod].second;
            if(lvl >= arr[it].first) {
                cur -= arr[it].second;
            }
            dp[nod] = max(dp[nod], cur + dp[it]);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 0, 1);
    dfs1(1, 0, 1);
    cout << dp[1];
    //cin.close();
    //cout.close();
    return 0;
}