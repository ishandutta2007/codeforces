#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, k;
    cin >> n >> k;
    if( n==0 ) {
        cout << 0;
        return 0;
    }
    int x=0, mod=10, wy=0;
    while( x < k && n ) {
        if( n%10 == 0 ) {
            x++;
        } else {
            wy++;
        }
        n /= 10;
    }
    if( x < k ) {
        cout << wy+x-1;
    } else
        cout << wy;

    return 0;
}