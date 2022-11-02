#include<bits/stdc++.h>

using namespace std;


bool tab[1010];
int dp[1000010];

vector<int> drogi;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, k;
    cin >> n >> k;
    for( int a, i=1; i<=k; i++ ) {
        cin >> a;
        tab[a] = true;
    }
    for( int i=0; i<=1000; i++ ) {
        if( tab[i] ) {
            drogi.push_back( -n+i );
        }
    }
    sort( drogi.begin(), drogi.end() );
    for( int i : drogi ) {
        i*=-1;
        if( i>0 ) {
            dp[i] = 1;
            for( int j=1; j+i<250000; j++ ) {
                if( dp[j] == 0 ) continue;
                if( dp[i+j] == 0 ) dp[i+j] = dp[j]+1;
                else dp[i+j] = min( dp[i+j], dp[j]+1 );
            }
        } else if( i<0 ) {
            for( int j=250000; j+i>=0; j-- ) {
                if( dp[j] == 0 ) continue;
                if( dp[i+j] == 0 ) dp[i+j] = dp[j]+1;
                else dp[i+j] = min( dp[i+j], dp[j]+1 );
            }
        } else {
            cout << 1;
            return 0;
        }
    }
    if( dp[0] == 0 ) {
        cout << -1;
    } else
        cout << dp[0];


    return 0;
}