#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    vector<int> v;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    vector<int> tab;
    for( int a, b, c, i=1; i<=m; i++ ) {
        cin >> a >> b >> c;
        if( a==1 )
        tab.push_back( b );
    }
    sort( v.begin(), v.end() );
    sort( tab.begin(), tab.end() );
    int res = n+m;
    v.push_back( 1000000000 );
    for( int i=0; i<v.size(); i++ ) {
        auto it = lower_bound( tab.begin(), tab.end(), v[i] );
        res = min( res, i+(tab.end()-it) );
    }
    cout << res;
    return 0;
}/*

*/