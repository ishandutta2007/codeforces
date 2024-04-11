#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mod 1000000009

vector<int> v1, v2, tab;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int x, y, l, r;
    cin >> x >> y >> l >> r;
    v1.push_back( 1 );
    for( int i=x, j=x%mod; i<=r && i%mod == j && i>=0; i*=x, j=(j*x)%mod ) {
        v1.push_back( i );
    }
    v2.push_back( 1 );
    for( int i=y, j=y%mod; i<=r && i%mod == j && i>=0; i*=y, j=(j*y)%mod ) {
        v2.push_back( i );
    }
    for( int i : v1 ) {
        for( int j : v2 ) {
            if( i+j > i && i+j >= l && i+j <= r )
                tab.push_back( i+j );
        }
    }
    tab.push_back( l-1 );
    tab.push_back( r+1 );
    sort( tab.begin(), tab.end() );
    int wy=0;
    for( int i=1; i<tab.size(); i++ ) {
        wy = max( wy, tab[i]-tab[i-1]-1 );
    }
    cout << wy;

    return 0;
}/*
1
3
1
1 5
*/