#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long sum;
int n, dist[c], ans[c], rf[c], ki[c], h[c], mp, maxi, db, pos, p=1;
bool v[c], v2[c];
vector<int> sz[c];
void dfs(int a) {
    v[a]=true, rf[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) dfs(x), rf[a]+=rf[x];
    }
    if (2*rf[a]>n) pos=a, rf[a]=0;
}
void dfs2(int a) {
    v2[a]=true;
    sum+=2*dist[a], h[ki[a]]++;
    if (h[ki[a]]>maxi) maxi=h[ki[a]], mp=ki[a];
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v2[x]) {
            dist[x]=dist[a]+1, ki[x]=ki[a];
            dfs2(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {int x, y; cin >> x >> y; sz[x].push_back(y), sz[y].push_back(x);}
    dfs(1), v2[pos]=1;
    for (int i=0; i<sz[pos].size(); i++) {
        int x=sz[pos][i];
        dist[x]=1, ki[x]=x, dfs2(x);
    }
    cout << sum << "\n";
    ki[pos]=pos;
    if (n%2) ans[pos]=pos;
    db=n/2-maxi;
    for (int i=1; i<=n; i++) {
        while(ans[p] || ki[p]==mp) p++;
        if (db && ki[i]!=ki[p] && !ans[i] && ki[i]!=mp) db--, ans[i]=p, ans[p]=i;
    }
    p=1;
    for (int i=1; i<=n; i++) {
        while(ans[p] || ki[p]==mp) p++;
        if (!ans[i] && ki[i]==mp) ans[i]=p, ans[p]=i;
    }
    if (n%2) {
        if (pos==1) swap(ans[1], ans[2]);
        else swap(ans[pos], ans[pos-1]);
    }
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}