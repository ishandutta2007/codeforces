#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int dp[5010][5010];
int odp[5010][5010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> dp[i][i];
        odp[i][i] = dp[i][i];
    }
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j+i<=n; j++ ) {
            dp[j][j+i] = dp[j][j+i-1]^dp[j+1][j+i];
            odp[j][j+i] = max( odp[j][j+i-1], odp[j+1][j+i] );
            odp[j][j+i] = max( odp[j][j+i], dp[j][j+i] );
        }
    }
    int q;
    cin >> q;
    for( int a, b, i=1; i<=q; i++ ) {
        cin >> a >> b;
        cout << odp[a][b] << "\n";
    }

    return 0;
}
/*

*/