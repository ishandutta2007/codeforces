#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, n, si[c], dp[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    si[a]=1;
    vector<int> le;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            le.push_back(x);
            si[a]+=si[x];
        }
    }
    int s=le.size();
    if (s==1) {
        dp[a]=si[a]-2;
    }
    if (s==2) {
        int x=le[0], y=le[1];
        dp[a]=max(si[x]-1+dp[y], si[y]-1+dp[x]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        //cout << "valalsz....................... ";
        cout << dp[1] << "\n";

        for (int i=1; i<=n; i++) {
            sz[i].clear(), si[i]=0, dp[i]=0, v[i]=0;
        }
    }
    return 0;
}
/*
1
7
1 2
1 5
2 3
2 4
5 6
5 7
*/