#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    int a=0, d=0;
    char c;
    cin >> n;
    for( int i=0; i<n; i++ ) {
        cin >> c;
        if( c == 'A' ) {
            a++;
        } else {
            d++;
        }
    }
    if( a > d ) {
        cout << "Anton";
    } else  if( a==d ) {
        cout << "Friendship";
    } else {
        cout << "Danik";
    }

    return 0;
}