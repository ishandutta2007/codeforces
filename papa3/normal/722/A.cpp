#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    int a, b;
    char x;
    cin >> a >> x >> b;

    if( n == 12 ) {
        if( 0 < a && a < 13 ) {

        } else if( a == 0 ) {
            a = 10;
        } else if( a < 20 ) {
            a = 10;
        } else if( a%10 == 0 ) {
            a = 10;
        } else
            a = a%10;
    } else {
        if( a > 23 ) {
            a = 10 + a%10;
        }
    }
    if( b >= 60 ) {
        b = 10 + b%10;
    }
    if( a < 10 ) {
        cout << 0;
    }
    cout << a << ':';
    if( b < 10 ) {
        cout << 0;
    }
    cout << b;

    return 0;
}