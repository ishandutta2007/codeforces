#include <bits/stdc++.h>

using namespace std;
const int c=19, h=270002;
int n, m, p;
bool el[c][c], cl[h];
long long mod=998244353, dp[270002], sum;
int main()
{
    cin >> n >> m, p=(1<<n), dp[0]=1;
    for (int i=1; i<=m; i++) {int a, b; cin >> a >> b; el[a][b]=1, el[b][a]=1;}
    for (int i=0; i<p; i++) {
        cl[i]=1;
        for (int j=0; j<n; j++) for (int k=0; k<n; k++) if (i&(1<<j) && (i&(1<<k)) && el[j+1][k+1]) cl[i]=0;
    }
    for (int i=1; i<p; i++) for (int j=i; j>=1; j=(j-1)&i) {
        if (cl[j]) {
            int x=__builtin_popcount(j);
            if (x%2) dp[i]+=dp[i-j];
            else dp[i]-=dp[i-j];
        }
    }
    sum=dp[p-1]%mod;
    if (sum%2) sum+=mod;
    cout << (sum*m/2)%mod;
    return 0;
}