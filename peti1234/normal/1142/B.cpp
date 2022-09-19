#include <bits/stdc++.h>

using namespace std;
int n, m, q;
int p[200001];
int t[200001];
int u[200001];
int e[200001];
int mini[200001];
int hova[200001];
bool v[200001];
vector<int> sz[200001];
int kov(int a)
{
    if (a==n) {
        return 1;
    }
    return a+1;
}
void dfs(int a, int b)
{
    //cout << a << " " << b << "\n";
    v[a]=true;
    mini[b]=a;
    if (b>=n) {
        hova[a]=mini[b-n+1];
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x, b+1);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m  >> q;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        p[x]=i;
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        t[i]=p[x];
    }
    for (int i=m; i>=1; i--) {
        int x=t[i];
        u[x]=i;
        if (u[kov(x)]!=0) {
            e[i]=u[kov(x)];
            sz[u[kov(x)]].push_back(i);
        }
    }
    /*for (int i=1; i<=m; i++) {
        cout << e[i] << " ";
        for (int j=0; j<sz[i].size(); j++) {
            cout << sz[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i=m; i>=1; i--) {
        if (!v[i]) {
            dfs(i, 1);
        }
    }
    for (int i=1; i<=m; i++) {
        if (hova[i]==0) {
            hova[i]=10000000;
        }
    }
    for (int i=m-1; i>=1; i--) {
        hova[i]=min(hova[i], hova[i+1]);
    }
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        if (hova[a]<=b) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}