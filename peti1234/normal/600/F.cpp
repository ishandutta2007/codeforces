#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int el[2*c][c], ans[100005], bal, jobb, maxi, m;
vector<int> sz[2*c];
map<pair<int, int>, int> id;
int ures(int a) {
    for (int i=1; i<=maxi; i++) {
        if (!el[a][i]) {
            return i;
        }
    }
}
void csere(int cs, int a, int b) {
    int kov=el[cs][a];
    swap(el[cs][a], el[cs][b]);
    if (kov) {
        csere(kov, b, a);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> bal >> jobb >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        b+=bal;
        id[{a, b}]=i;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=bal+jobb; i++) {
        maxi=max(maxi, (int)sz[i].size());
    }
    for (int i=1; i<=bal; i++) {
        for (auto x:sz[i]) {
            int bu=ures(i), ju=ures(x);
            el[i][bu]=x, el[x][ju]=i;
            if (bu!=ju) {
                csere(x, bu, ju);
            }
        }
    }
    for (int i=1; i<=bal; i++) {
        for (int j=1; j<=maxi; j++) {
            int x=el[i][j];
            ans[id[{i, x}]]=j;
        }
    }
    cout << maxi << "\n";
    for (int i=1; i<=m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}