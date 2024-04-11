#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    vector<pair<int, int> > v;
    int n;
    cin >> n;
    for( int a, b, c, d, i=1; i<=n; i++ ) {
        cin >> a >> b >> c >> d;
        v.push_back( {-a-b-c-d, i} );
    }
    sort( v.begin(), v.end() );
    for( int i=0; i<n; i++ ) {
        if( v[i].second == 1 ) {
            cout << i+1;
            return 0;
        }
    }

    return 0;
}
/*

*/