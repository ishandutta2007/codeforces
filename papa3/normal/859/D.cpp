#include<bits/stdc++.h>

using namespace std;

#define int long long

int tab[1000][1000];
long double dp[400][100];
long double hajs[400][100];
int n;

void policz( int where ) {
    int ile=n/2;
    int x=1;
    while( x*2 <= where ) {
        x*=2;
        ile/=2;
    }
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=n; j++ ) {
            dp[where][i] += dp[where*2][i]*dp[where*2+1][j]*tab[i][j]/100;
            dp[where][i] += dp[where*2+1][i]*dp[where*2][j]*tab[i][j]/100;
        }
    }
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=n; j++ ) {
            if( dp[where*2][i] > 0.00000000001 )
                hajs[where][i] = max( hajs[where][i], ile*dp[where][i]+hajs[where*2][i]+hajs[where*2+1][j] );
            else
                hajs[where][i] = max( hajs[where][i], ile*dp[where][i]+hajs[where*2][j]+hajs[where*2+1][i] );
        }
        if( dp[where][i] < 0.00000000001 ) hajs[where][i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n;
    n = 1<<n;
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=n; j++ ) {
            cin >> tab[i][j];
        }
    }
    for( int i=n; i<2*n; i++ ) {
        dp[i][i-n+1] = 1;
    }
    for( int i=n-1; i>0; i-- ) {
        policz( i );
    }
    long double wy=0;
    for( int i=1; i<=n; i++ ) {
        wy = max( hajs[1][i], wy );
    }
    cout << fixed << setprecision( 20 ) << wy;

    return 0;
}