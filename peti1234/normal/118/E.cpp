#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, baj, eler[c], visz[c], f[c], cnt;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    cnt++, eler[a]=cnt, visz[a]=cnt;
    for (int x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            if (visz[x]==eler[x]) {
                baj=1;
            }
            visz[a]=min(visz[a], visz[x]);
        } else {
            if (x!=f[a]) {
                visz[a]=min(visz[a], eler[x]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    if (baj) {
        cout << 0 << "\n";
    } else {
        for (int i=1; i<=n; i++) {
            for (int j:sz[i]) {
                if (j>i) {
                    int x=i, y=j;
                    if (eler[x]>eler[j]) swap(x, y);
                    if (f[y]!=x) swap(x, y);
                    cout << x << " " << y << "\n";
                }
            }
        }
    }
    return 0;
}