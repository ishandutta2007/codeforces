#include <bits/stdc++.h>

using namespace std;
const int c=302;
int w, n, t[c][c], pos[3], mh;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<3; i++) pos[i]=0, mh=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char x; cin >> x;
                if (x=='.') t[i][j]=0;
                if (x=='X') t[i][j]=1;
                if (x=='O') t[i][j]=2;
                if (t[i][j]==1) {
                    pos[(i+j)%3]++;
                }
            }
        }
        for (int i=0; i<3; i++) {
            if (pos[i]<pos[mh]) mh=i;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if ((i+j)%3==mh && t[i][j]==1) t[i][j]=2;
                if (t[i][j]==0) cout << '.';
                if (t[i][j]==1) cout << 'X';
                if (t[i][j]==2) cout << 'O';
            }
            cout << "\n";
        }
    }
    return 0;
}