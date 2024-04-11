#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, k, val[c], xo;
vector<int> sz[c];
bool v[c];
int dfs(int a) {
    v[a]=true;
    int ert=0;
    for (auto x:sz[a]) {
        if (!v[x]) {
            int s=dfs(x);
            val[a]^=val[x];
            if (s==2) {
                return 2;
            }
            if (xo==0 && s==1) {
                return 1;
            }
            ert+=s;
        }
    }
    if (ert>=2) {
        return 2;
    }
    if (ert==1) {
        return 1+(val[a]==0);
    }
    return (val[a]==xo);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> val[i];
            xo^=val[i];
        }
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        int res=dfs(1);
        if (xo!=0 && k==2) {
            res=0;
        }
        if (xo==0 && res==1 || xo!=0 && res==2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        for (int i=1; i<=n; i++) {
            v[i]=0;
            sz[i].clear();
        }
        xo=0;
    }
    return 0;
}