#include <bits/stdc++.h>

using namespace std;
int w;
int n, m, a, b;
bool v[52][52];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m >> a >> b;
        for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) v[i][j]=0;
        if (n*a!=m*b) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            int db=n*a, x=0, y=0;
            while(db) {
                if (!v[x][y]) v[x][y]=1, db--, x++, y++;
                else x++;
                x%=n, y%=m;
            }
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) cout << v[i][j];
                cout << endl;
            }
        }
    }
    return 0;
}