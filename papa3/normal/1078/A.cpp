#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

double man( double a, double b, double c, double d ) {
    return abs( a-c )+abs( b-d );
}

double dist( double a, double b, double c, double d ) {
    return sqrt( (a-c)*(a-c) + (b-d)*(b-d) );
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int a, b;
    double c, x1, y1, y2, x2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

    double res = abs( x1-x2 ) + abs( y1-y2 );

    if( a==0 || b==0 ) {
        cout << fixed << setprecision( 10 ) << res;
        return 0;
    }

    vector<pair<double, double> > v;
    v.push_back( {-(c+b*y1)/a, y1} );
    v.push_back( {-(c+b*y2)/a, y2} );
    v.push_back( {x1, -(c+a*x1)/b} );
    v.push_back( {x2, -(c+a*x2)/b} );
    for( auto i : v ) {
        for( auto j : v ) {
            res = min( res, man( x1, y1, i.first, i.second ) +
                            dist( i.first, i.second, j.first, j.second ) +
                            man( j.first, j.second, x2, y2 ) );
        }
    }
    cout << fixed << setprecision( 10 ) << res;

    return 0;
}/*

*/