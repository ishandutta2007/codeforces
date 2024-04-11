#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int w, n, m, maxi, db, szint[c], f[c], pos;
bool v[c];
vector<int> sz[c], h[c];
void dfs(int a) {
    int p=szint[a], si=h[p].size();
    v[a]=1, maxi=max(maxi, p);
    if (maxi==p) pos=a;
    h[p].push_back(a), db+=si%2;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            f[x]=a, szint[x]=szint[a]+1;
            dfs(x);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, maxi=0, db=0, pos=0;
        for (int i=1; i<=n; i++) szint[i]=0, f[i]=0, v[i]=0, sz[i].clear(), h[i].clear();
        szint[1]=1;
        for (int i=1; i<=m; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        if (2*maxi>=n) {
            cout << "PATH\n" << maxi << "\n" << pos << " ";
            while(pos!=1) pos=f[pos], cout << pos << " ";
            cout << "\n";
        } else {
            cout << "PAIRING\n" << db << "\n";
            for (int i=1; i<=maxi; i++) for (int j=1; j<h[i].size(); j+=2) cout << h[i][j-1] << " " << h[i][j] << "\n";
        }
    }
    return 0;
}