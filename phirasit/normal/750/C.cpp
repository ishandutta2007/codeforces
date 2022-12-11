#include <iostream>

using namespace std;

const int inf = 1e8;
const int N = 2e5 + 10;

int n;

int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    int a = -inf, b = inf;
    int div2 = 0;

    cin >> n;
    for ( int i = 0 ; i < n ; ++i ) {
        int c, d;
        cin >> c >> d;
        if ( d == 1 ) {
            a = max( a, 1900 );
        } else {
            b = min( b, 1899 );
            div2 = true;
        }

        a += c;
        b += c;
    }

    if ( !div2 ) {
        cout << "Infinity" << endl;
    } else if ( a > b ) {
        cout << "Impossible" << endl;
    } else {
        cout << b << endl;
    }

    return 0;
}