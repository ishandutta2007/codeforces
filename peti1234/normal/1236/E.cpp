#include <bits/stdc++.h>

using namespace std;
const int c=200005, f=100000;
long long ans=0;
int n, m, t[c], szint[c][2], kezd[c][2];
vector<int> dif[c][2], sz[c][2];
void dfs(int a, int b) {
    for (auto x:sz[a][b]) {
        szint[x][b]=szint[a][b]+1;
        dfs(x, b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> t[i];
        int s[2]={i+f-t[i], i+t[i]};
        for (int j=0; j<2; j++) {
            if (!kezd[s[j]][j]) {
                kezd[s[j]][j]=i;
            }
            int ert=s[j]-1;
            while (dif[ert][j].size()>0) {
                sz[i][j].push_back(dif[ert][j].back());
                dif[ert][j].pop_back();
            }
            dif[s[j]][j].push_back(i);
        }

    }
    if (n==1) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i=m; i>=1; i--) {
        for (int j=0; j<2; j++) {
            if (!szint[i][j]) {
                szint[i][j]=1;
                dfs(i, j);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        int mini=max(1, i-m-1), maxi=min(n, i+m+1);
        if (kezd[i][1]) {
            mini=max(1, i-m-1+szint[kezd[i][1]][1]);
        }
        if (kezd[f-i][0]) {
            maxi=min(n, i+m+1-szint[kezd[f-i][0]][0]);
        }
        ans+=maxi-mini+1;
    }
    cout << ans << "\n";
    return 0;
}