#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, a, b;
    cin >> n;
    for( int i=0; i<n; i++ ) {
        cin >> a;
        swap( a, b );
    }
    if( n == 1 ) {
        if( b == 0 ) {
            cout << "UP";
        } else if( b == 15 ) {
            cout << "DOWN";
        } else {
            cout << -1;
        }
    } else {
        if( b == 15 ) {
            cout << "DOWN";
        } else if( b == 0 ) {
            cout << "UP";
        } else {
            if( b > a ) {
                cout << "UP";
            } else {
                cout << "DOWN";
            }
        }
    }
    return 0;
}