#include <bits/stdc++.h>

using namespace std;
const int f=1002, c=202;
long long mod=1e9+7, regi[c][f], uj[c][f], sum;
int n, p, t[c];
void cp() {
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=p; j++) {
            regi[i][j]=uj[i][j];
            uj[i][j]=0;
        }
    }
}
int main()
{
    cin >> n >> p;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    regi[0][0]=1;
    for (int i=1; i<=n; i++) {
        int dif=t[i]-t[i-1];
        for (int j=0; j<=i; j++) {
            for (int k=0; k<=p; k++) {
                if (k+j*dif<=p) {
                    uj[j][k+j*dif]=regi[j][k];
                }
            }
        }
        cp();
        for (int j=0; j<=i; j++) {
            for (int k=0; k<=p; k++) {
                uj[j][k]+=regi[j][k]; // kln
                uj[j][k]+=regi[j][k]*j, uj[j][k]%=mod; // kzpre ll
                uj[j+1][k]+=regi[j][k]; // j csapat
                if (j) {
                    uj[j-1][k]+=regi[j][k]*j; // csapat lezrs
                    uj[j-1][k]%=mod;
                }
            }
        }
        cp();
    }
    for (int i=0; i<=p; i++) {
        sum+=regi[0][i];
    }
    cout << sum%mod << "\n";
    return 0;
}