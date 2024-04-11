#include <bits/stdc++.h>

using namespace std;
const int c=2022;
long long n, m, sum, alatt[2*c][2*c], koms[c][c], komo[c][c], mod=998244353;
long long bin(int a, int b) {
    return alatt[a+b][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    alatt[0][0]=1;
    for (int i=1; i<=n+m; i++) {
        alatt[i][0]=1;
        for (int j=1; j<=i; j++) {
            alatt[i][j]=(alatt[i-1][j]+alatt[i-1][j-1])%mod;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            long long pr=bin(n-i, j-1)*bin(n-i+1, m-j)%mod;

            sum+=pr*koms[i-1][j-1];
            sum%=mod;
            koms[i][j]=bin(i, j-1)*bin(i-1, m-j);
            koms[i][j]+=koms[i][j-1];
            koms[i][j]%=mod;

            pr=bin(n-i, m-j+1)*bin(i-1, m-j)%mod;
            if (i>2) {
                sum+=pr*komo[i-2][j-1];
            }
            sum%=mod;
            komo[i][j]=bin(i-1, j)*bin(n-i, j-1);
            komo[i][j]+=komo[i-1][j];
            komo[i][j]%=mod;
        }
    }
    cout << 2*sum%mod << "\n";
    return 0;
}