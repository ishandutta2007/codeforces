#include <bits/stdc++.h>

using namespace std;
const int c=502;
int w, n, m, s[c*c], o[c*c], t[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int x; cin >> x;
                o[x]=j;
            }
        }
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                int x; cin >> x;
                s[x]=j;
            }
        }
        for (int i=1; i<=n*m; i++) {
            t[s[i]][o[i]]=i;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cout << t[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}