#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    vector<int> v;
    int mi=numeric_limits<int>::max(), ma=0;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        mi = min( a, mi );
        ma = max( a, ma );
        v.push_back( a );
    }
    int wy=0;
    for( int i : v ) {
        if( mi < i && i < ma ) {
            wy++;
        }
    }
    cout << wy;

    return 0;
}