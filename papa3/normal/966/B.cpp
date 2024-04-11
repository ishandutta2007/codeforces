#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

vector<pair<int, int> > v;
int n, x1, x2;

bool algo( bool czy ) {
    int i=0;
    for( ; i<n; i++ ) {
        if( (x1-1)/(i+1)+1 <= v[i].first )
            break;
    }
    if( i==n ) return 0;
    int j=i+1;
    for( ; j<n; j++ ) {
        if( (x2-1)/(j-i)+1 <= v[j].first )
            break;
    }
    if( j==n ) return 0;

    cout << "Yes\n";
    if( czy ) {
        cout << i+1 << " " << j-i << "\n";
        for( int x=0; x<=i; x++ ) cout << v[x].second << " ";
        cout << "\n";
        for( int x=i+1; x<=j; x++ ) cout << v[x].second << " ";
    } else {
        cout << j-i << " " << i+1 << "\n";
        for( int x=i+1; x<=j; x++ ) cout << v[x].second << " ";
        cout << "\n";
        for( int x=0; x<=i; x++ ) cout << v[x].second << " ";
    }

    return 1;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> x1 >> x2;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v.push_back( {a, i} );
    }
    sort( v.begin(), v.end() );
    reverse( v.begin(), v.end() );

    if( !algo( 1 ) ) {
        swap( x1, x2 );
        if( !algo( 0 ) ) {
            cout << "No";
        }
    }

    return 0;
}
/*

*/