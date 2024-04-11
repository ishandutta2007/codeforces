#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int g[MAXN + 1][2];
int gr[MAXN + 1];
int val[MAXN + 1];
map <int, char> mp;
int ans = 0;

void dfs(int nod, int l, int r) {
     if(l <= val[nod] && val[nod] <= r)
        mp[val[nod]] = 1;
     if(g[nod][0] > -1)
        dfs(g[nod][0], l, min(r, val[nod] - 1));
     if(g[nod][1] > -1)
        dfs(g[nod][1], max(l, val[nod] + 1), r);
}

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> val[i] >> g[i][0] >> g[i][1];
        if(g[i][0] > -1)
          gr[g[i][0]]++;
        if(g[i][1] > -1)
          gr[g[i][1]]++;
    }
    i = 1;
    while(gr[i] > 0)
        i++;
    ans = 0;
    dfs(i, -(1 << 30), (1 << 30));
    for(i = 1; i <= n; i++)
        ans += 1 - mp[val[i]];
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}