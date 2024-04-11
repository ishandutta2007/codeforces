#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, aa, bb, da, db, dist, maxi, tav[c], le[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    if (a==bb) dist=tav[a];
    v[a]=true;
    int e=0, m=0;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            tav[x]=tav[a]+1;
            dfs(x);
            m=max(m, le[x]+1);
            if (m>e) swap(e, m);
        }
    }
    maxi=max(maxi, e+m);
    le[a]=e;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> aa >> bb >> da >> db, maxi=0, dist=0;
        for (int i=1; i<=n; i++) sz[i].clear(), v[i]=0, tav[i]=0, le[i]=0;
        for (int i=1; i<n; i++) {
            int x, y; cin >> x >> y;
            sz[x].push_back(y), sz[y].push_back(x);
        }
        dfs(aa);
        if (dist>da && db>2*da && maxi>2*da) cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}
// 1. lps!