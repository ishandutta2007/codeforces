#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mod 1000000007ll

multiset<int> pocz[2], kon[2];
pair<int, int> p[1000010], k[1000010];

int32_t main(){
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, b, c, d, i=1; i<=n; i++ ) {
        cin >> a >> b >> c >> d;
        pocz[0].insert( a );
        pocz[1].insert( b );
        kon[0].insert( c );
        kon[1].insert( d );
        p[i] = {a, b};
        k[i] = {c, d};
    }

    for( int i=1; i<=n; i++ ) {
        pocz[0].erase( pocz[0].find( p[i].first ) );
        pocz[1].erase( pocz[1].find( p[i].second ) );
        kon[0].erase( kon[0].find( k[i].first ) );
        kon[1].erase( kon[1].find( k[i].second ) );
        if( *pocz[0].rbegin() <= *kon[0].begin() && *pocz[1].rbegin() <= *kon[1].begin() ) {
            cout << *pocz[0].rbegin() << " " << *pocz[1].rbegin();
            return 0;
        }
        pocz[0].insert( p[i].first );
        pocz[1].insert( p[i].second );
        kon[0].insert( k[i].first );
        kon[1].insert( k[i].second );
    }

    return 0;
}