#include<bits/stdc++.h>

using namespace std;

long long n, k, s, t;
vector<long long> stacje;
vector<pair<long long, long long> > samo;

long long policz( long long c ) {
    long long poprzedni = 0, c2;
    long long wy=0;
    for( long long i : stacje ) {
        if( i - poprzedni > c ) {
            return numeric_limits<int>::max();
        } else {
            wy += 2*( i-poprzedni );
            c2 = c - ( i-poprzedni );
            wy -= min( i-poprzedni, c2 );
        }
        poprzedni = i;
    }
    return wy;
}

long long ser() {
    long long pocz=0; long long kon = numeric_limits<int>::max(), sr;
    while( kon - pocz > 1 ) {
        sr = (pocz+kon)/2;
        if( policz( sr ) <= t ) {
            kon = sr;
        } else {
            pocz = sr;
        }
    }
    return pocz+1;
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    cin >> n >> k >> s >> t;
    for( long long a, b, i=0; i<n; i++ ) {
        cin >> a >> b;
        samo.push_back( {a, b} );
    }
    for( long long a, i=0; i<k; i++ ) {
        cin >> a;
        stacje.push_back( a );
    }
    sort( stacje.begin(), stacje.end() );
    stacje.push_back( s );
    long long x = ser();
    long long wy = numeric_limits<int>::max();
    for( pair<long long, long long> & i : samo ) {
        if( i.second >= x && i.first < wy ) {
            wy = i.first;
        }
    }
    if( wy == numeric_limits<int>::max() ) {
        cout << -1;
    } else {
        cout << wy;
    }
    return 0;
}