#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];

int c[MAXN + 1];

int dp[MAXN + 1];

int ans = 0;


void dfs(int nod, int col) {
    if(c[nod] != col)
        ans++;
    for(auto it : g[nod])
        dfs(it, c[nod]);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
    }
    for(i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1, 0);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}