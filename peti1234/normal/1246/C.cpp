#include <bits/stdc++.h>

using namespace std;
const int c=2005;
long long mod=1000000007;
long long n, m, kom[c][c], jj[c][c], jjkom[c][c], jm[c][c], l[c][c], llkom[c][c], lm[c][c];
bool v[c][c];

long long ossz(long long a, long long b, long long c, long long d) {
    return kom[c][d]-kom[a-1][d]-kom[c][b-1]+kom[a-1][b-1];
}
long long jkom(long long a, long long b, long long c, long long d) {
    return (jjkom[c][d]-jjkom[a-1][d]-jjkom[c][b-1]+jjkom[a-1][b-1]+mod)%mod;
}
long long lkom(long long a, long long b, long long c, long long d) {
    return (llkom[c][d]-llkom[a-1][d]-llkom[c][b-1]+llkom[a-1][b-1]+mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i=1; i<=n; i++) {
        for (long long j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='R') {
                v[i][j]=true;
            }
            kom[i][j]=kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1]+v[i][j];
        }
    }
    for (long long i=1; i<=n; i++) {
        long long x=1, y=1;
        while(y<=m) {
            if (ossz(i, x+1, i, m)<=m-y) {
                jm[i][y]=x;
                y++;
            } else {
                x++;
            }
        }
    }
    for (long long i=1; i<=m; i++) {
        long long x=1, y=1;
        while(y<=n) {
            if (ossz(x+1, i, n, i)<=n-y) {
                lm[y][i]=x;
                y++;
            } else {
                x++;
            }
        }
    }
    jj[1][1]=1, l[1][1]=1;
    jjkom[1][1]=1, llkom[1][1]=1;
    for (long long i=1; i<=n; i++) {
        for (long long j=1; j<=m; j++) {
            if (i+j>2) {
                l[i][j]=jkom(i, jm[i][j], i, j-1)%mod;
                jj[i][j]=lkom(lm[i][j], j, i-1, j)%mod;
                jjkom[i][j]=(jjkom[i-1][j]+jjkom[i][j-1]-jjkom[i-1][j-1]+jj[i][j])%mod;
                llkom[i][j]=(llkom[i-1][j]+llkom[i][j-1]-llkom[i-1][j-1]+l[i][j])%mod;
            }
        }
    }
    if (n==1 && m==1) {
        cout << 1 << endl;
        return 0;
    }
    cout << (jj[n][m]+l[n][m])%mod << "\n";
    return 0;
}