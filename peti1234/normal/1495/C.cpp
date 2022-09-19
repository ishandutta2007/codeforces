#include <bits/stdc++.h>

using namespace std;
const int c=505;
int w, n, m;
bool v[c][c], jo[c];
bool u(int a) {
    if (a<=0 || a>=m+1 || !v[2][a]) {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m+1; i++) {
            jo[i]=0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c; cin >> c;
                v[i][j]=(c=='X');
            }
        }
        if (n==1 || m==1) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    cout << 'X';
                }
                cout << "\n";
            }
            continue;
        }
        for (int j=1; j<=m; j++) {
            v[1][j]=1;
        }
        for (int j=1; j<=m; j++) {
            if ((j<=2 || !jo[j-2]) && u(j-1) && u(j+1)) {
                jo[j]=1;
                for (int i=1; i<=n; i++) {
                    v[i][j]=1;
                }
            }
        }
        if (n>=4 && m>=4 && !jo[m] && !jo[m-1] && !jo[m-2]) {
            //cout << "specialis\n";
            jo[m]=1;
            for (int i=3; i<=n; i++) {
                v[i][m]=1;
            }
            if (v[n-1][m-2] || v[n-1][m-1]) {
                v[n-1][m-2]=1, v[n-1][m-1]=1;
            } else {
                v[n][m-2]=1, v[n][m-1]=1;
            }
        }
        for (int i=3; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (v[i][j]) {
                    if (!jo[j-1] && !jo[j] && !jo[j+1]) {
                        if (j>2 && jo[j-2]) {
                            v[i][j-1]=1;
                        } else if (j<m-1 && jo[j+2]) {
                            v[i][j+1]=1;
                        } else {
                            while (true) {

                            }
                        }
                    }
                }
            }
        }
        //cout << "valasz:\n";
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (v[i][j]) {
                    cout << "X";
                } else {
                    cout << ".";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
/*
1
5 4
....
..X.
....
.X..
....
*/