#include <bits/stdc++.h>

using namespace std;
int p[101];
int q[101];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while(w--) {
        int n, m;
        bool c=true;
        cin >> n >> m;
        for (int i=1; i<=n; i++) cin >> p[i];
        for (int i=1; i<=m; i++) cin >> q[i];
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int x=q[j];
                if (p[x]>p[x+1]) swap(p[x], p[x+1]);
            }
        }
        for (int i=1; i<n; i++) if (p[i]>p[i+1]) c=false;
        if (c) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}