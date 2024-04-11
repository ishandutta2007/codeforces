#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, ans[c], szint[c], fel[c], f[c], pos, pkor, baj;
vector<int> sz[c], s[c], nagy, kicsi, comp;
bool v[c], v2[c];
void dfs(int a) {
    v[a]=1, comp.push_back(a);
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v[x]) szint[x]=szint[a]+1, fel[x]=y, f[x]=a, dfs(x);
        else if ((szint[a]+szint[x])%2==0 && !pkor) {
            int sum=y, paros=0, el=0, ert=a; pkor=1, pos=a;
            if (a==x) ans[a]=y/2;
            else {
                while(ert!=x) {
                    if (el%2) paros+=fel[ert];
                    sum+=fel[ert], el++;
                    ert=f[ert];
                }
                ans[a]=sum/2-paros;
            }
        }
    }
}
void dfs2(int a) {
    v2[a]=1;
    if (ans[a]>0) nagy.push_back(ans[a]);
    else kicsi.push_back(ans[a]);
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!v2[x]) ans[x]=y-ans[a], dfs2(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y, z;
        cin >> x >> y >> z, z*=2;
        sz[x].push_back(y), sz[y].push_back(x), s[x].push_back(z), s[y].push_back(z);
    }
    for (int i=1; i<=n; i++) if (!v[i]) {
        nagy.clear(), kicsi.clear(), comp.clear(), pos=i, pkor=0;
        dfs(i);
        if (!pkor) ans[i]=c;
        dfs2(pos);
        if (!pkor) {
            int x=0, y=3*c, z, si=comp.size(), db;
            while(y-x>1) {
                z=(x+y)/2, db=0;
                for (int i=0; i<nagy.size(); i++) db+=(nagy[i]-z<0);
                for (int i=0; i<kicsi.size(); i++) db+=(kicsi[i]+z>0);
                if (2*db>si) y=z;
                else x=z;
            }
            for (int i=0; i<si; i++) {
                int p=ans[comp[i]];
                if (p<0) p+=x;
                else p-=x;
                ans[comp[i]]=p;
            }
        }
    }
    for (int i=1; i<=n; i++) for (int j=0; j<sz[i].size(); j++) {
        int x=sz[i][j];
        if (ans[i]+ans[x]!=s[i][j]) baj++;
    }
    if (baj) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            double x=ans[i];
            cout << x/2 << " ";
        }
        cout << "\n";
    }
    return 0;
}