#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define MAX_N 300010

int n, r, l;
vector<int> v[2];
int  tab[100010];
int dp[2][100010];
int s[2];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> l >> r;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
    }
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v[a].push_back( tab[i] );
        s[a]+=tab[i];
    }

    sort( v[1].begin(), v[1].end() );
    int kon = r-l;
    for( int x : v[1] ) {
        for( int i = s[1]; i>=0; i-- ) {
            if( i<=kon ) {
                dp[1][i+x] = max( dp[1][i+x], dp[1][i]+1 );
            } else if( dp[1][i] ) {
                dp[1][i+x] = max( dp[1][i+x], dp[1][i] );
            }
        }
    }
    dp[0][0] = 1;
    for( int x : v[0] ) {
        for( int i = s[0]; i>=0; i-- ) {
            if( dp[0][i] ) {
                dp[0][i+x] = 1;
            }
        }
    }
    int res=0;
    for( int i=0; i<=s[0]; i++ ) {
        if( dp[0][i] ) {
            if( s[1]+s[0]-i-l >=0 )
                res = max( res, dp[1][ s[1]+s[0]-i-l ] );
        }
    }
    cout << res;


    return 0;
}
/*
2 5
abab
ab

*/