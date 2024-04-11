#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<pair<int, int> > v;
int t1[1000010], t2[1000010];
bool czy[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, k, wy=0;
    cin >> n >> k;
    for( int i=1; i<=n; i++ ) {
        cin >> t1[i];
    }
    for( int i=1; i<=n; i++ ) {
        cin >> t2[i];
        v.push_back( {t1[i]-t2[i], i} );
    }
    sort( v.begin(), v.end() );
    for( int i=0; i<k; i++ ) {
        wy += t1[ v[i].second ];
        czy[ v[i].second ] = 1;
    }
    for( int i=1; i<=n; i++ ) {
        if( czy[i] == 0 ) {
            wy += min( t1[i], t2[i] );
        }
    }
    cout << wy;
    return 0;
}