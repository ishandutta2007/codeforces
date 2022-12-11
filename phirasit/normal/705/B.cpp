#include <iostream>

using namespace std;

int main( void ) {

    cin.sync_with_stdio( false );
    cin.tie( 0 );

    int n;
    cin >> n;

    for ( int i = 0, ans = 1 ; i < n ; ++i ) {
        int val;
        cin >> val;
        if ( val % 2 == 0 ) ans = not ans;
        cout << ( ans + 1 ) << "\n";
    }

    return 0;
}