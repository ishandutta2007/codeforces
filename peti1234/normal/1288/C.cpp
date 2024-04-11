#include <bits/stdc++.h>

using namespace std;
int n, m;
long long mod=1000000007;
long long alatt[2101][2101];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<=n+2*m; i++) {
        alatt[i][0]=1;
        for (int j=1; j<=i; j++) {
            alatt[i][j]=(alatt[i-1][j]+alatt[i-1][j-1])%mod;
        }
    }
    cout << alatt[2*m+n-1][2*m] << endl;
    return 0;
}