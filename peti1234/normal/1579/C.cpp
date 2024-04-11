#include <bits/stdc++.h>

using namespace std;
const int c=25;
int w, n, m, k;
bool t[c][c], jo[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                t[i][j]=(c=='*');
            }
        }

        for (int i=k+1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                bool s=t[i][j];
                for (int f=1; f<=k; f++) {
                    if (!t[i-f][j-f] || !t[i-f][j+f]) {
                        s=0;
                        break;
                    }
                }
                if (s) {
                    jo[i][j]=1;
                    int db=1;
                    while (t[i-db][j-db] && t[i-db][j+db]) {
                        jo[i-db][j-db]=1, jo[i-db][j+db]=1;
                        db++;
                    }
                }
            }
        }

        bool baj=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (t[i][j] && !jo[i][j]) {
                    baj=1;
                }
                t[i][j]=jo[i][j]=0;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}
/*
1
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...
*/