#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=20;
int n, ert[c];
long long ans, dp[c][k][2];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<k; i++) {
        bool s=(ert[a] & (1<<i));
        if (s) dp[a][i][1]=1;
        else dp[a][i][0]=1;
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            for (int i=0; i<k; i++) {
                for (int j=0; j<2; j++) {
                    long long s=(1<<i);
                    ans=ans+s*dp[a][i][1-j]*dp[x][i][j];
                }
                for (int j=0; j<2; j++) {
                    bool s=(ert[a] & (1<<i));
                    dp[a][i][j^s]+=dp[x][i][j];
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
        ans+=ert[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}
/*
3
0 1 1
1 2
2 3

*/