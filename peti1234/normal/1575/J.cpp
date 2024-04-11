#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, t[c][c], q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=q; i++) {
        int x=1, y;
        cin >> y;
        while (x<=n) {
            int s=t[x][y];
            t[x][y]=2;
            if (s==1) y++;
            if (s==3) y--;
            if (s==2) x++;
        }
        cout << y << " ";
    }
    cout << "\n";
    return 0;
}