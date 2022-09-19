#include <bits/stdc++.h>

using namespace std;
const int c=102, f=-1e6;
int n, m, k;
long long kdp[c][c][c], ndp[c][c], res[c];
int main()
{
    cin >> n >> m >> k;
    for (int i=0; i<=n; i++) for (int j=0; j<=k; j++) ndp[i][j]=f;
    ndp[0][0]=0;
    for (int i=1; i<=n; i++) {
        for (int i=0; i<=m; i++) for (int j=0; j<=m; j++) for (int s=0; s<k; s++) kdp[i][j][s]=f, res[s]=f;
        for (int j=0; j<=m; j++) kdp[j][0][0]=0;
        res[0]=0;
        for (int j=1; j<=m; j++) {
            int x; cin >> x;
            for (int l=1; l<=m/2; l++) {
                for (int s=0; s<k; s++) {
                    kdp[j][l][s]=max(kdp[j-1][l][s], kdp[j-1][l-1][(s-x+c*k)%k]+x);
                    res[s]=max(res[s], kdp[j][l][s]);
                }
            }
        }
        for (int j=0; j<k; j++) {
            for (int l=0; l<k; l++) {
                ndp[i][l]=max(ndp[i][l], ndp[i-1][j]+res[(l-j+k)%k]);
            }
        }
    }
    cout << ndp[n][0] << "\n";
    return 0;
}
/*
1 2 4
1 2
*/