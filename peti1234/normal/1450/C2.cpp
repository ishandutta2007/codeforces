#include <bits/stdc++.h>

using namespace std;
const int c=302;
int w, n, t[c][c], ox[3], xo[3], xv, ov, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<3; i++) ox[i]=0, xo[i]=0, ov=0, xv=0, db=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char x; cin >> x;
                if (x=='.') t[i][j]=0;
                if (x=='X') t[i][j]=1;
                if (x=='O') t[i][j]=2;
                if (t[i][j]==1) {
                    ox[(i+j)%3]++;
                }
                if (t[i][j]==2) {
                    xo[(i+j)%3]++;
                }
                if (t[i][j]) {
                    db++;
                }
            }
        }
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i!=j && ox[i]+xo[j]<=db/3) xv=i, ov=j;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if ((i+j)%3==xv && t[i][j]==1) t[i][j]=2;
                if ((i+j)%3==ov && t[i][j]==2) t[i][j]=1;
                if (t[i][j]==0) cout << '.';
                if (t[i][j]==1) cout << 'X';
                if (t[i][j]==2) cout << 'O';
            }
            cout << "\n";
        }
    }
    return 0;
}