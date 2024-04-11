#include <bits/stdc++.h>

using namespace std;
const int c=52;
long long n, e, dp[c][c][c][c], mod=1000000007, kh[c], q, sum;
int main()
{
    cin >> n >> q >> e; kh[0]=1;
    if (e!=1) dp[1][0][1][0]=1;
    if (e!=0) dp[1][0][0][0]=1;
    for (int i=1; i<=n; i++) kh[i]=kh[i-1]*2%mod;
    for (int pos=2; pos<=n; pos++) {
        int x;
        cin >> x;
        for (int a=0; a<pos; a++) for (int b=0; a+b<pos; b++) for (int c=0; a+b+c<pos; c++) {
            int d=pos-1-a-b-c;
            long long el=kh[pos-2], ert=dp[pos-1][a][b][c], r=ert*el%mod;
            if (x!=1) {
                if (d>0) dp[pos][a+1][b][c]+=r;
                else dp[pos][a][b+1][c]+=r;
                dp[pos][a][b+1][c]+=r;
            }
            if (x!=0) {
                if (b>0) dp[pos][a][b][c+1]+=r;
                else dp[pos][a][b][c]+=r;
                dp[pos][a][b][c]+=r;
            }
        }
    }
    for (int a=0; a<=n; a++) for (int b=0; a+b<=n; b++) for (int c=0; a+b+c<=n; c++) {
        int d=n-a-b-c;
        if ((b+d+q)%2==0) sum+=dp[n][a][b][c];
    }
    cout << sum%mod << "\n";
    return 0;
}