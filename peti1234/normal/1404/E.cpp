#include <bits/stdc++.h>

using namespace std;
const int c=202, p=2*c*c;
int n, m, db, cs, sum, par[p], f[c][c];
vector<int> sz[p], akt;
bool v[p], jo[p], t[c][c];
int ki(int a, int b) {
    if (a>b) swap(a, b);
    if (b-a==m) return a+n*m;
    return a;
}
void add(int a, int b) {
    sz[a].push_back(b);
}
bool dfs(int a) {
    v[a]=1, akt.push_back(a);
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            if (!par[x]) {
                par[a]=x, par[x]=a;
                return 1;
            }
            if (!v[par[x]]) {
                v[x]=1, akt.push_back(x);
                if (dfs(par[x])) {
                    par[a]=x, par[x]=a;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            f[i][j]=(i-1)*m+j;
            char x; cin >> x;
            if (x=='#') {
                t[i][j]=1, jo[f[i][j]]=1;
                db++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i][j]) {
                int a=f[i][j], b=f[i][j-1], c=f[i][j+1], d=f[i-1][j], e=f[i+1][j];
                if (t[i][j-1]) cs++;
                if (t[i-1][j]) cs++;
                if (t[i][j-1]) {
                    if (t[i-1][j]) add(ki(a, b), ki(a, d));
                    if (t[i+1][j]) add(ki(a, b), ki(a, e));
                }
                if (t[i][j+1]) {
                    if (t[i-1][j]) add(ki(a, c), ki(a, d));
                    if (t[i+1][j]) add(ki(a, c), ki(a, e));
                }
            }
        }
    }
    for (int i=1; i<=n*m; i++) sort(sz[i].rbegin(), sz[i].rend());
    for (int i=1; i<=n*m; i++) {
        if (jo[i] &&  i%m) {
            if (dfs(i)) {
                sum++;
                for (int i=0; i<akt.size(); i++) v[akt[i]]=0;
            }
        }
        akt.clear();
    }
    cout << db-cs+sum << "\n";
    return 0;
}