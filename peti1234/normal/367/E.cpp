#include <bits/stdc++.h>

using namespace std;
const int c=402;
long long n, m, s, regi[c][c], uj[c][c], ans, mod=1e9+7;
int main()
{
    cin >> n >> m >> s;
    if (n>m) {
        cout << 0 << "\n";
        return 0;
    }
    regi[0][0]=1;
    for (int p=1; p<=m; p++) {
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=i; j++) {
                long long ert=0;
                if (i>0) {
                    ert+=regi[i-1][j];
                    if (j>0) {
                        ert+=regi[i-1][j-1];
                    }
                }
                if (j>0 && p!=s) {
                    ert+=regi[i][j-1];
                }
                if (p!=s) {
                    ert+=regi[i][j];
                }
                if (p<s && i==n) {
                    ert=0;
                }
                uj[i][j]=ert;
            }
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                regi[i][j]=uj[i][j]%mod;
                uj[i][j]=0;
            }
        }
    }
    ans=regi[n][n];
    for (int i=1; i<=n; i++) {
        ans*=i;
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}