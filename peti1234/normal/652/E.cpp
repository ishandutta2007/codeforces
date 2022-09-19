#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, m, kezd, veg, cnt, db, eler[c], visz[c], f[c];
vector<int> sz[c], s[c];
bool v[c], v2[c], jo[c], h[c];
void dfs(int a) {
    v[a]=true;
    if (a==veg) {
        jo[a]=true;
    }
    eler[a]=visz[a]=++cnt;
    for (int x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            jo[a]|=jo[x];
            visz[a]=min(visz[a], visz[x]);
            if (visz[x]>eler[a] && !jo[x]) {
                h[x]=1;
            }
        } else if (f[a]!=x) {
            visz[a]=min(visz[a], eler[x]);
        }
    }
}
void dfs2(int a) {
    v2[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        if (!h[x]) {
            db+=y;
            if (!v2[x]) {
                dfs2(x);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a), s[a].push_back(c), s[b].push_back(c);
    }
    cin >> kezd >> veg;
    dfs(kezd);
    dfs2(kezd);
    cout << (db ? "YES" : "NO") << "\n";
    return 0;
}