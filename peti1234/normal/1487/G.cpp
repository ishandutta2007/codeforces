#include <bits/stdc++.h>

using namespace std;
const int c=402, k=26;
long long mod=998244353, sum=k*k, n, mdb, db[k+1], regi[c][c][3][3], uj[c][c][3][3], dp[c][c];
int main()
{
    cin >> n;
    mdb=n/2+1;
    for (int i=1; i<=k; i++) {
        cin >> db[i];
    }
    regi[2][0][0][0]=regi[0][2][1][1]=1, regi[1][1][0][1]=regi[1][1][1][0]=1;
    regi[1][0][0][2]=regi[1][0][2][0]=regi[0][1][1][2]=regi[0][1][2][1]=k-2;
    regi[0][0][2][2]=(k-2)*(k-2);
    for (int l=3; l<=n; l++) {
        sum*=k-1, sum%=mod;
        for (int i=0; i<=mdb; i++) {
            for (int j=0; j<=mdb; j++) {
                for (int u=0; u<3; u++) {
                    for (int v=0; v<3; v++) {
                        long long x=regi[i][j][u][v];
                        if (u!=0) {
                            uj[i+1][j][v][0]+=x;
                        }
                        if (u!=1) {
                            uj[i][j+1][v][1]+=x;
                        }
                        if (u!=2) {
                            uj[i][j][v][2]+=x*(k-2);
                        } else {
                            uj[i][j][v][2]+=x*(k-3);
                        }
                    }
                }
            }
        }
        for (int i=0; i<=mdb; i++) {
            for (int j=0; j<=mdb; j++) {
                for (int u=0; u<3; u++) {
                    for (int v=0; v<3; v++) {
                        regi[i][j][u][v]=uj[i][j][u][v]%mod;
                        uj[i][j][u][v]=0;
                    }
                }
            }
        }
    }
    for (int i=0; i<=mdb; i++) {
        for (int j=0; j<=mdb; j++) {
            for (int u=0; u<3; u++) {
                for (int v=0; v<3; v++) {
                    dp[i][j]+=regi[i][j][u][v];
                }
            }
        }
    }
    for (int i=1; i<=k; i++) {
        for (int j=db[i]+1; j<=n; j++) {
            for (int m=0; m<=n; m++) {
                sum-=dp[j][m];
            }
        }
        for (int j=i+1; j<=k; j++) {
            for (int a=db[i]+1; a<=n; a++) {
                for (int b=db[j]+1; b<=n; b++) {
                    sum+=dp[a][b];
                }
            }
        }
    }
    sum%=mod;
    if (sum<0) {
        sum+=mod;
    }
    cout << sum << "\n";
    return 0;
}