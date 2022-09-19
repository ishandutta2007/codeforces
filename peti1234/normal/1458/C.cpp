#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int w, n, q, t[c][c], sol[c][c], pos[3], ert[3], x[3];
string s;
int m(int x) {
    x%=n;
    x+=n;
    if (x>n) x-=n;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> q;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cin >> t[i][j];
            }
        }
        cin >> s;
        for (int i=0; i<3; i++) pos[i]=i, ert[i]=0;
        for (int i=0; i<q; i++) {
            char c=s[i];
            if (c=='U') ert[pos[0]]--;
            if (c=='D') ert[pos[0]]++;
            if (c=='L') ert[pos[1]]--;
            if (c=='R') ert[pos[1]]++;
            if (c=='I') swap(pos[1], pos[2]);
            if (c=='C') swap(pos[0], pos[2]);
        }
        for (x[0]=1; x[0]<=n; x[0]++) {
            for (x[1]=1; x[1]<=n; x[1]++) {
                x[2]=t[x[0]][x[1]];
                sol[m(x[pos[0]]+ert[pos[0]])][m(x[pos[1]]+ert[pos[1]])]=m(x[pos[2]]+ert[pos[2]]);
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}