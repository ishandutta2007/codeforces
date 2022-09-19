#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long x[c], y[c];
vector<int> sz[c], s;
int dp[c][20], szint[c], n, m;
bool f(int a, int b, int c) {return (x[b]-x[a])*(y[c]-y[a])<(x[c]-x[a])*(y[b]-y[a]);}
void dfs(int a) {
    for (int i=1; i<20; i++) dp[a][i]=dp[dp[a][i-1]][i-1];
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        dp[x][0]=a, szint[x]=szint[a]+1,  dfs(x);
    }
}
int main()
{
    cin >> n, s.push_back(n);
    for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
    for (int i=n-1; i>=1; i--) {
        while(s.size()>1) {
            int si=s.size(), a=s[si-2], b=s[si-1];
            if (f(a, b, i)) s.pop_back();
            else break;
        }
        sz[s.back()].push_back(i), s.push_back(i);
    }
    szint[n]=1, dfs(n), cin >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        if (szint[x]<szint[y]) swap(x, y);
        for (int i=19; i>=0; i--) if (szint[dp[x][i]]>=szint[y]) x=dp[x][i];
        for (int i=19; i>=0; i--) if (dp[x][i]!=dp[y][i]) x=dp[x][i], y=dp[y][i];
        if (x!=y) x=dp[x][0];
        cout << x << " ";
    }
    return 0;
}