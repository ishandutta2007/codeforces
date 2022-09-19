#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, t[c][c], ert[c][c], s[c][c], o[c][c], cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='*') t[i][j]=1;

            ert[i][j]=min({i-1, j-1, n-i, m-j});
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!t[i][j]) {
                ert[i][j]=0;
                for (int a=i-1; a>=1; a--) {
                    ert[a][j]=min(ert[a][j], i-a-1);
                    if (!t[a][j]) break;
                }
                for (int a=i+1; a<=n; a++) {
                    ert[a][j]=min(ert[a][j], a-i-1);
                    if (!t[a][j]) break;
                }
                for (int b=j-1; b>=1; b--) {
                    ert[i][b]=min(ert[i][b], j-b-1);
                    if (!t[i][b]) break;
                }
                for (int b=j+1; b<=m; b++) {
                    ert[i][b]=min(ert[i][b], b-j-1);
                    if (!t[i][b]) break;
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int f=ert[i][j];
            if (f) {
                cnt++;
                s[i][j-f]++;
                s[i][j+f+1]--;
                o[i-f][j]++;
                o[i+f+1][j]--;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            s[i][j]+=s[i][j-1];
            o[i][j]+=o[i-1][j];
            //cout << "ertek " << t[i][j] << " " << s[i][j] << " " << o[i][j] << "\n";
            if (t[i][j] && !s[i][j] && !o[i][j]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << cnt << "\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (ert[i][j]) cout << i << " " << j << " " << ert[i][j] << "\n";
        }
    }
    return 0;
}
/*
4 4
.**.
****
****
.*..
*/