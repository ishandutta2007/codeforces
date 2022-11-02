#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    double n, H;
    cin >> n >> H;
    double P = H/2;
    double x = P/n, p=0;
    for( int i=1; i<n; i++ ) {
        p += x;
        cout << fixed << sqrt( p/P*H*H ) << "\n";
    }

    return 0;
}