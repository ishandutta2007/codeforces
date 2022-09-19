#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, gy, cnt=1, ert[c], p[c], e[c], db[402], f[c];
bool v[c], q, h[402];
vector<int> sz[c], sol;
void dfs(int a) {
    v[a]=true, e[a]=cnt, cnt++;
    if (!q && p[a]>=gy-1) {
        q=1;
        int mini=a, w=a;
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i];
            if (v[x] && e[x]<e[mini]) mini=x;
        }
        while(w!=mini) sol.push_back(w), w=f[w];
        //for (int i=1; i<=n; i++) if (w!=mini) sol.push_back(w), w=f[w];
        sol.push_back(mini);
        for (int i=1; i<=n; i++) v[i]=1;
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (v[x]) h[ert[x]]=1;
    }
    for (int i=1; i<gy; i++) {
        if (!h[i] && !ert[a]) ert[a]=i, db[i]++;
        h[i]=0;
    }
    for (int i=0; i<sz[a].size(); i++) p[sz[a][i]]++;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            f[x]=a;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, gy=sqrt(n);
    if (gy*gy<n) gy++;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    if (q) {
        cout << 2 << "\n" << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
    } else {
        cout << 1 << "\n";
        for (int i=1; i<=gy; i++) {
            if (db[i]>=gy) {
                for (int j=1; j<=n; j++) if (gy && ert[j]==i) cout << j << " " , gy--;
                return 0;
            }
        }
    }
    return 0;
}