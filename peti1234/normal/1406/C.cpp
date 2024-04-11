#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, c1, c2, sp, rf[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    int mgy=0;
    v[a]=1, rf[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            mgy=max(mgy, rf[x]);
            rf[a]+=rf[x];
        }
    }
    if (2*rf[a]>=n && 2*mgy<=n) {
        if (!c1) c1=a;
        else c2=a;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, c1=0, c2=0, sp=0;
        for (int i=1; i<=n; i++) v[i]=0, sz[i].clear(), rf[i]=0;
        for (int i=1; i<n; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        if (!c2) {
            cout << c1 << " " << sz[c1][0] << "\n" << c1 << " " << sz[c1][0] << "\n";
        } else {
            int x=sz[c2][0];
            if (x==c1) x=sz[c2][1];
            cout << c2 << " " << x << "\n";
            cout << c1 << " " << x << "\n";
        }
    }
    return 0;
}