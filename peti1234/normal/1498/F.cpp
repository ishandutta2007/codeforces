#include <bits/stdc++.h>

using namespace std;
const int c=100002, h=42;
int n, k, ert[c][h];
vector<int> sz[c];
bool v[c], v2[c], ans[c];
void add(int a, int b) {
    for (int i=0; i<2*k; i++) {
        int kov=(i+1)%(2*k);
        ert[a][kov]^=ert[b][i];
    }
}
void calc(int a) {
    int xo=0;
    for (int i=k; i<2*k; i++) {
        xo^=ert[a][i];
    }
    ans[a]=xo;
}
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            add(a, x);
        }
    }
}
void dfs2(int a) {
    v2[a]=true;
    calc(a);
    for (int x:sz[a]) {
        if (!v2[x]) {
            add(a, x);
            add(x, a);
            dfs2(x);
            add(x, a);
            add(a, x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        cin >> ert[i][0];
    }
    dfs(1);
    dfs2(1);
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}