#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, k, u, db[c][c], aa[c], bb[c], ans[c];
vector<int> sz[c], s[c], inv[c];
void dfs(int a, int regi, int uj) {
    for (int i=0; i<sz[a].size(); i++) {
        int b=sz[a][i], cl=s[a][i], rev=inv[a][i];
        if (cl==regi) {
            db[a][regi]--, db[a][uj]++;
            db[b][regi]--, db[b][uj]++;
            s[a][i]=-uj, s[b][rev]=-uj;
            dfs(b, uj, regi);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> u;
    }
    for (int id=1; id<=m; id++) {
        int a, b;
        cin >> a >> b;
        aa[id]=a, bb[id]=b;
        int mini=1, maxi=1;
        for (int i=1; i<=k; i++) {
            if (db[a][i]<db[a][mini]) {
                mini=i;
            }
        }
        inv[a].push_back(sz[b].size()), inv[b].push_back(sz[a].size());
        sz[a].push_back(b), s[a].push_back(mini);
        sz[b].push_back(a), s[b].push_back(mini);
        db[a][mini]++, db[b][mini]++;

        mini=1, maxi=1;
        for (int i=1; i<=k; i++) {
            if (db[b][i]<db[b][mini]) {
                mini=i;
            }
            if (db[b][i]>db[b][maxi]) {
                maxi=i;
            }
        }
        if (db[b][maxi]-db[b][mini]>=3) {
            dfs(b, maxi, mini);
            for (int i=1; i<=n; i++) {
                for (int j=0; j<s[i].size(); j++) {
                    s[i][j]=abs(s[i][j]);
                }
            }
        }
        for (int i=1; i<=n; i++) {
            int mini=db[i][1], maxi=db[i][1];
            for (int j=1; j<=k; j++) {
                mini=min(mini, db[i][j]), maxi=max(maxi, db[i][j]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j], cl=s[i][j];
            for (int id=1; id<=m; id++) {
                if (aa[id]==i && bb[id]==x) {
                    ans[id]=cl;
                }
            }
        }
    }
    for (int i=1; i<=m; i++) {
        cout << ans[i] << "\n";
    }
    cout << "\n";
    return 0;
}