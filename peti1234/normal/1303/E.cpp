#include <bits/stdc++.h>

using namespace std;
const int c=402;
int regi[c][c], uj[c][c], w, n, m;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        n=a.size(), m=b.size();
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=m; j++) {
                regi[i][j]=-1;
                uj[i][j]=-1;
            }
            regi[i][i]=0;
        }
        for (int i=0; i<n; i++) {
            for (int kezd=1; kezd<=m; kezd++) {
                for (int veg=kezd; veg<=m; veg++) {
                    int s=regi[kezd][veg];
                    if (s!=-1) {
                        uj[kezd][veg]=max(uj[kezd][veg], s);
                        if (s<m && a[i]==b[s]) {
                            uj[kezd][veg]=max(uj[kezd][veg], s+1);
                        }
                        if (veg<m && a[i]==b[veg]) {
                            uj[kezd][veg+1]=max(uj[kezd][veg+1], s);
                        }
                    }
                }
            }
            for (int kezd=1; kezd<=m; kezd++) {
                for (int veg=1; veg<=m; veg++) {
                    regi[kezd][veg]=uj[kezd][veg];
                    uj[kezd][veg]=-1;
                }
            }
        }
        bool jo=0;
        for (int kezd=1; kezd<=m; kezd++) {
            if (regi[kezd][m]>=kezd) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
x
x
*/