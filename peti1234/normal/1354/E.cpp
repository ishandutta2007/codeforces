#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, m, ert[c], l[c][c], db[2*c], x, y, f, w, cnt=1;
vector<int> sz[c];
bool dp[c][c], kell[2*c],  pk;
void dfs(int a) {
    if (!ert[a]) ert[a]=cnt;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!ert[x]) ert[x]=-ert[a], dfs(x);
        if (ert[x]==ert[a]) pk=1;
    }
    if (ert[a]<0) ert[a]=cnt+1;
    db[ert[a]]++;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> w >> f >> y;
    for (int i=1; i<=m; i++) {
        cin >> x >> y;
        sz[x].push_back(y), sz[y].push_back(x);
    }
    for (int i=1; i<=n; i++) if (!ert[i]) dfs(i), cnt+=2;
    /*for (int i=1; i<=n; i++) cout << ert[i] << " ";
    cout << endl;
    for (int i=1; i<=cnt; i++) cout << db[i] << " ";
    cout << endl;*/
    dp[0][0]=1, cnt--;
    for (int i=1; i<=cnt; i+=2) {
        int pos=(i+1)/2;
        for (int j=f; j>=0; j--) {
            int a=db[i], b=db[i+1];
            if (j>=a && dp[pos-1][j-a]) dp[pos][j]=1, l[pos][j]=i;
            if (j>=b && dp[pos-1][j-b]) dp[pos][j]=1, l[pos][j]=i+1;
        }
    }
    /*for (int i=0; i<=cnt/2; i++) {
        for (int j=0; j<=n; j++) {
            cout << dp[i][j]<< " ";
        }
        cout << endl;
    }*/
    if (!pk && dp[cnt/2][f]) {
        cout << "YES" << "\n";
        for (int i=cnt; i>=2; i-=2) {
            if (l[(i+1)/2][f]==i) kell[i]=1, f-=db[i];
            else kell[i-1]=1, f-=db[i-1];
        }
        for (int i=1; i<=n; i++) {
            if (kell[ert[i]]) cout << 2;
            else if (w) cout << 1, w--;
            else cout << 3;
        };
    } else cout << "NO";
    return 0;
}