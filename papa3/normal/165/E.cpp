#include<bits/stdc++.h>

using namespace std;

int dp[6000000];

struct algo {
    int n;
    vector<int> v;
    algo() {
        cin >> n;
        for( int i=0; i<6000000; i++ ) {
            dp[i] = -1;
        }
        for( int a, i=1; i<=n; i++ ) {
            cin >> a;
            dp[a] = max( dp[a], a );
            v.push_back( a );
        }
        for( int i=0; i<=22; i++ ) {
            for( int mask=0; mask<(1<<22); mask++ ) {
                if( (1<<i) & mask ) dp[mask] = max( dp[mask^(1<<i)], dp[mask] );
            }
        }
        for( int i : v ) {
            cout << dp[ i^(1<<22)-1 ] << " ";
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    algo p;

    return 0;
}
/*

*/