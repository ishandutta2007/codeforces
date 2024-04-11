#include <bits/stdc++.h>

using namespace std;
const int c=100002, d=10;
int n, f, kov[c][d], db[c][d], t[c];
long double ert[c][d];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> f;
    for (int i=0; i<d; i++) {
        kov[0][i]=-1;
    }
    kov[0][1]=0;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        for (int j=0; j<d; j++) {
            if (kov[i-1][j]!=-1) {
                kov[i][j]=j;
                db[i][j]=db[i-1][j];
                ert[i][j]=ert[i-1][j];
            } else {
                kov[i][j]=-1;
            }
        }
        long double add=log(t[i]);
        for (int j=0; j<d; j++) {
            int p=(j*t[i]%d);
            if (kov[i-1][j]!=-1 && ert[i-1][j]+add>=ert[i][p]) {;
                kov[i][p]=j;
                db[i][p]=db[i-1][j]+1;
                ert[i][p]=ert[i-1][j]+add;
            }
        }
    }
    if (db[n][f]==0) {
        cout << -1 << "\n";
        return 0;
    }
    cout << db[n][f] << "\n";
    int s=f;
    for (int i=n; i>=1; i--) {
        if (db[i][s]>db[i-1][kov[i][s]]) {
            cout << t[i] << " ";
        }
        s=kov[i][s];
    }
    cout << "\n";
    return 0;
}
/*
3 3
9 8 17
*/