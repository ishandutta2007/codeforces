#include <bits/stdc++.h>

using namespace std;
const int c=52;
int n, m, db[c], f[c];
bool fix[c][c], er[c][c], v[c];
int dfs(int a, int p) {
    v[a]=true;
    if (db[a]+2<=db[p]) {
        db[a]++, db[p]--;
        while(a!=p) swap(er[a][f[a]], er[f[a]][a]), a=f[a];
        return true;
    }
    for (int i=1; i<=n; i++) {
        if (!fix[a][i] && !v[i] && er[a][i]) {
            f[i]=a;
            if (dfs(i, p)) return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        fix[a][b]=1, fix[b][a]=1, er[a][b]=1, db[a]++;
    }
    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (!fix[i][j]) er[i][j]=1, db[i]++;
    while(true) {
        int jav=0, maxi=1;
        for (int i=1; i<=n; i++) v[i]=0, f[i]=0;
        while(maxi && !jav) {
            maxi=0;
            for (int i=1; i<=n; i++) if (!v[i] && db[i]>db[maxi]) maxi=i;
            jav=dfs(maxi, maxi);
        }
        if (!jav) break;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << er[i][j];
        cout << "\n";
    }
    return 0;
}