#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

vector<pair<double, double> > kola;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    double r;
    cin >> n >> r;
    double a;
    for( int i=0; i<n; i++ ) {
        cin >> a;
        double res = r;
        for( auto & i : kola ) {
            double b = abs( i.first-a  );
            if( b <= 2*r ) {
                res = max( res, i.second+sqrt( 4*r*r-b*b ) );
            }
        }
        cout << fixed << setprecision( 10 ) << res << " ";
        kola.push_back( {a, res} );
    }

    return 0;
}