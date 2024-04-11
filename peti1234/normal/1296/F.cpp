#include <bits/stdc++.h>

using namespace std;
const int c=5002, k=14;
int n, q, ert[c], ans[c], szint[c], fel[c][k], cs1[c], cs2[c], val[c];
vector<int> sz[c];
vector<pair<int, int> > el;
bool v[c], baj;
void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            a=fel[a][i];
        }
    }
    if (a==b) {
        return a;
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    return fel[a][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        el.push_back({a, b});
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> cs1[i] >> cs2[i] >> val[i];
        int a=cs1[i], b=cs2[i], koz=lca(a, b);
        while (a!=koz) {
            ert[a]=max(ert[a], val[i]);
            a=fel[a][0];
        }
        while (b!=koz) {
            ert[b]=max(ert[b], val[i]);
            b=fel[b][0];
        }
    }
    for (int i=1; i<=q; i++) {
        int a=cs1[i], b=cs2[i], koz=lca(a, b);
        bool jo=0;
        while (a!=koz) {
            if (ert[a]==val[i]) {
                jo=1;
            }
            a=fel[a][0];
        }
        while (b!=koz) {
            if (ert[b]==val[i]) {
                jo=1;
            }
            b=fel[b][0];
        }
        if (!jo) {
            baj=1;
        }
    }
    if (baj) {
        cout << -1 << "\n";
    } else {
        for (int i=0; i<n-1; i++) {
            int a=el[i].first, b=el[i].second;
            if (szint[a]<szint[b]) {
                swap(a, b);
            }
            //cout << a << " " << b << "\n";
            cout << max(1, ert[a]) << " ";
        }
        cout << "\n";
    }
    return 0;
}