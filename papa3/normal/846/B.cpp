#include<bits/stdc++.h>

using namespace std;

#define int long long

multiset<int> se;
vector<int> v;
int suma;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, k, m;
    cin >> n >> k >> m;
    for( int a, i=1; i<=k; i++ ) {
        cin >> a;
        v.push_back( a );
        suma += a;
    }
    int res = 0;
    for( int i=0; i<=n; i++ ) {
        int koszt = 0;
        int wy=0;
        for( int j=0; j<i; j++ ) {
            koszt += suma;
            wy += k+1;
        }
        if( koszt > m ) break;
        se.clear();
        for( int x : v ) {
            for( int j=0; j<n-i; j++ ) {
                se.insert( x );
            }
        }
        while( !se.empty() && koszt+*se.begin() <= m ) {
            koszt+=*se.begin();
            se.erase( se.begin() );
            wy++;
        }
        res = max( wy, res );
    }
    cout << res;

    return 0;
}