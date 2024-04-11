#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    string a;
    cin >> n >> a;
    int b1=0, r1=0, b2=0, r2=0;
    for( int i=0; i<n; i++ ) {
        if( a[i] == 'b' ) {
            if( i%2 == 0 ) {
                b2++;
            } else {
                b1++;
            }
        } else {
            if( i%2 == 0 ) {
                r1++;
            } else {
                r2++;
            }
        }
    }
    cout << min( max( b1, r1 ), max( b2, r2 ) );
    return 0;
}