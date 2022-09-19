#include <bits/stdc++.h>

using namespace std;
int w, n, m, cnt, t[6][6];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                int x=(c=='R' ? 1 : 0);
                t[i][j]=(t[i-1][j]+t[i][j-1]-t[i-1][j-1]+x);
                if (x && t[i][j]==1) cnt++;
            }
        }
        cout << (cnt==1 ? "YES" : "NO") << "\n";
        cnt=0;
    }
    return 0;
}