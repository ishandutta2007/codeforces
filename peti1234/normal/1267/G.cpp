#include <bits/stdc++.h>

using namespace std;
const int c=102, k=100005;
int n, ert, sum;
long double nn, x, ans, fakt[c], sum2, regi[c][k], uj[c][k];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    nn=n;
    fakt[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i;
    }

    regi[0][0]=1;
    for (int i=1; i<=n; i++) {
        cin >> ert;
        for (int j=0; j<i; j++) {
            for (int k=0; k<=sum; k++) {
                uj[j][k]+=regi[j][k];
                uj[j+1][k+ert]+=regi[j][k];
            }
        }
        sum+=ert;
        for (int j=0; j<=i; j++) {
            for (int k=0; k<=sum; k++) {
                regi[j][k]=uj[j][k];
                uj[j][k]=0;
            }
        }
    }
    sum2=sum;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=sum; j++) {
            long double ii=i, jj=j;
            ans+=(fakt[i]*fakt[n-i]/fakt[n])*min((sum2-jj)/(nn-ii), ((ii/(nn-ii)+2)*x/2))*regi[i][j];
        }
    }
    cout.precision(20);
    cout << ans << "\n";
    return 0;
}