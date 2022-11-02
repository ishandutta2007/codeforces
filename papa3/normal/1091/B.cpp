#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

map<pair<int, int>, int> m;
vector<pair<int, int> > v, p;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        v.push_back( {a, b} );
    }
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        p.push_back( {a, b} );
    }

    int ma=0;

    for( pair<int, int> i : v ) {
        for( pair<int, int> j : p ) {
            ma = max( ma, ++m[ {i.first+j.first, i.second+j.second} ] );
        }
    }
    for( auto i : m ) {
        if( i.second == ma ) {
            cout << i.first.first << " " << i.first.second;
            return 0;
        }
    }



    return 0;
}/*

*/