#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, ert[c], si[c], ans;
vector<int> sz[c];
void dfs(int a) {
    si[a]=1;
    for (auto x:sz[a]) {
        dfs(x);
        si[a]+=si[x];
        ert[a]+=ert[x];
    }
    if (2*ert[a]==si[a]) ans++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=2; i<=n; i++) {
            int x;
            cin >> x;
            sz[x].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            if (c=='W') ert[i]=1;
        }
        dfs(1);
        cout << ans << "\n";

        for (int i=1; i<=n; i++) {
            ert[i]=0, si[i]=0;
            sz[i].clear();
        }
        ans=0;
    }
    return 0;
}