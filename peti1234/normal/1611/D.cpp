#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, f[c], dist[c], ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> f[i];
        bool baj=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (i==1 && f[x]==x) dist[x]=1;
            if (!dist[f[x]]) baj=1;
            dist[x]=i;
            ans[x]=dist[x]-dist[f[x]];
        }
        if (baj) cout << -1;
        else for (int i=1; i<=n; i++) cout << ans[i] << " ";
        cout << "\n";
        for (int i=1; i<=n; i++) f[i]=dist[i]=ans[i]=0;
    }
    return 0;
}