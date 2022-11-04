#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e5;

std::vector <int> g[MAXN + 1];

double dp[MAXN + 1];

void dfs(int nod, int father) {
    double x = 0;
    for(auto it : g[nod])
       if(father != it) {
           dfs(it, nod);
           dp[nod] += dp[it];
           x++;
       }
    if(x > 0) {
       dp[nod] /= x;
       dp[nod]++;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    cout << setprecision(20) << dp[1];
    //cin.close();
    //cout.close();
    return 0;
}