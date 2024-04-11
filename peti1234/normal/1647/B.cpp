#include <bits/stdc++.h>

using namespace std;
int w, n, m, t[105][105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                t[i][j]=(c=='1' ? 1 : 0);
            }
        }
        bool jo=1;
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (t[i][j]+t[i+1][j]+t[i][j+1]+t[i+1][j+1]==3) {
                    jo=0;
                }
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}