#include <iostream>

using namespace std;


const int N = 1000;
long long min_require[ N ];

int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    long long n;
    cin >> n;

    min_require[ 0 ] = 1ll;
    min_require[ 1 ] = 2ll;
    int i;
    for ( i = 2 ; min_require[i-1] <= n ; ++i ) {
        min_require[ i ] = min_require[ i-2 ] + min_require[ i-1 ];
    }

    cout << i-2 << endl;

    return 0;
}