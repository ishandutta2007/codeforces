#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    int n, nwd, maks;
    cin >> n >> nwd;
    maks = nwd;
    for( int a, i=1; i<n; i++ ) {
        cin >> a;
        nwd = __gcd( nwd, a );
        maks = max( maks, a );
    }
    if( (maks/nwd-n)%2 == 1 ) {
        cout << "Alice";
    } else {
        cout << "Bob";
    }
    return 0;
}