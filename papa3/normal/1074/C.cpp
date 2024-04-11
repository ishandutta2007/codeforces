#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

vector<pair<int, int> > v;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    pair<int, int> x;
    pair<int, int> y;
    cin >> x.first >> y.first;
    v.push_back( {x.first, y.first} );
    x.second = x.first;
    y.second = y.first;
    for( int a, b, i=2; i<=n; i++ ) {
        cin >> a >> b;
        v.push_back( {a, b} );
        x.first = min( x.first, a );
        x.second = max( x.second, a );
        y.first = min( y.first, b );
        y.second = max( y.second, b );
    }
    int res=0;
    for( pair<int, int> i : v ) {
        res = max( res,
                  max( abs(i.first -x.first), abs(i.first -x.second) )  +
                  max( abs(i.second-y.first), abs(i.second-y.second) )  );

    }
    cout << res*2;
    for( int i=4; i<=n; i++ ) {
        cout << " " << (x.second-x.first+y.second-y.first)*2;
    }
    return 0;
}/*

*/