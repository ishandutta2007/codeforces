#include <bits/stdc++.h>

using namespace std;
int w, db[55][55], n, m;
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
                if (c=='*') db[i][j]=1;
                if (c=='o') db[i][j]=-1;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (db[i][j]>0 && i<n && db[i+1][j]!=-1) {
                    db[i+1][j]+=db[i][j];
                    db[i][j]=0;
                }
            }
        }
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=m; j++) {
                if (db[i][j]>1) {
                    db[i-1][j]+=db[i][j]-1;
                    db[i][j]=1;
                }
            }
        }
        //cout << "valasz:\n";
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (db[i][j]==1) cout << '*';
                if (db[i][j]==0) cout << '.';
                if (db[i][j]==-1) cout << 'o';
            }
            cout << "\n";
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                db[i][j]=0;
            }
        }
    }
    return 0;
}