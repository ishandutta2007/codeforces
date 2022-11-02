#include<bits/stdc++.h>

using namespace std;

string tab[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    string a, b;
    int x, y;
    cin >> a >> b;
    for( int i=0; i<7; i++ ) {
        if( tab[i] == a ) {
            x = i;
        }
        if( tab[i] == b ) {
            y = i;
        }
    }
    if( x == y || (x+2)%7 == y || (x+3)%7 == y ) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}