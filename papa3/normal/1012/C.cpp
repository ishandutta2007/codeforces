#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007LL
#define INF 1000000000000000000LL

int dp[5010][3010][2];
int tab[5010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n/2+1; i++ ) {
        dp[0][i][0] = dp[0][i][1] = INF;
        dp[1][i][0] = dp[1][i][1] = INF;
    }
    tab[0] = tab[1] = -INF;
    for( int i=2; i<=n+1; i++ ) cin >> tab[i];
    for( int i=2; i<=n+1; i++ ) {
        for( int j=1; j<=(n+1)/2; j++ ) {
            dp[i][j][0] = min( dp[i-1][j][0], dp[i-1][j][1]+max( 0ll, tab[i]-tab[i-1]+1 ) );
            dp[i][j][1] = min( dp[i-2][j-1][0]+max( 0ll, tab[i-1]-tab[i]+1 ), dp[i-2][j-1][1]+max( 0ll, max(tab[i-1]-tab[i]+1, tab[i-1]-tab[i-2]+1) ) );
        }
    }
    for( int i=1; i<=(n+1)/2; i++ ) {
        cout << min( dp[n+1][i][0], dp[n+1][i][1] ) << " ";
    }

    return 0;
}
/*

*/