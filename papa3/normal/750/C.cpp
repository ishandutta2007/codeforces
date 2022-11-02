#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    long long mi=-numeric_limits<int>::max(), ma=numeric_limits<int>::max();
    int n, div;
    cin >> n;
    int a, b, suma;
    cin >> a >> b;
    if( b == 1 ) {
        mi = 1900;
    } else {
        ma = 1899;
    }
    suma = a;
    for( int i=1; i<n; i++ ) {
        cin >> a >> b;
        if( b == 1 ) {
            mi += max( 1900-mi-suma, 0ll );
        } else {
            ma -= max( ma+suma-1899, 0ll );
        }
        suma += a;
    }
    if( mi > ma ) {
        cout << "Impossible";
    } else if( ma == numeric_limits<int>::max() ) {
        cout << "Infinity";
    } else {
        cout << ma+suma;
    }

    return 0;
}