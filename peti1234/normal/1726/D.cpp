#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, m, bal[c], jobb[c], szint[c], fel[c], spec[c], spec1, spec2, spec3;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            fel[x]=a;
            szint[x]=szint[a]+1;
            dfs(x);
        } else {
            if (fel[a]!=x && szint[a]>szint[x]) {
                //cout << "vissza " << a << " " << x << "\n";
                spec[a]++, spec[x]++;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        bal[i]=x, jobb[i]=y;
        sz[x].push_back(y), sz[y].push_back(x);
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=n; i++) {
        if (spec[i]==2) {
            //cout << "fontos " << i << "\n";
            if (!spec1) spec1=i;
            else if (!spec2) spec2=i;
            else spec3=i;
        }
    }
    if (spec3) {
        if (szint[spec1]<szint[spec2]) {
            swap(spec1, spec2);
        }
    } else {
        spec1=0, spec2=0, spec3=0;
    }

    for (int i=1; i<=m; i++) {
        int x=bal[i], y=jobb[i];
        if (szint[x]<szint[y]) swap(x, y);
        bool alap=(y==fel[x]);
        bool valt=(x==spec1 && y==spec2 || x==spec1 && y==fel[x]);
        cout << (alap==valt ? 0 : 1);
    }
    cout << "\n";

    for (int i=1; i<=max(n, m); i++) {
        v[i]=0, szint[i]=0, fel[i]=0;
        sz[i].clear(), spec[i]=0, jobb[i]=0, bal[i]=0;
    }
    spec1=0, spec2=0, spec3=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5
*/
// n=2, n=3
// nullazas