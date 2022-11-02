#include<bits/stdc++.h>

using namespace std;

#define int long long

const int pot = 1ll << 60ll;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, q;
    cin >> n >> q;
    while( q-- ) {
        int where;
        string s;
        cin >> where >> s;
        for( char c : s ) {
            int nwd = __gcd( pot, where );
            if( c=='U') {
                if( nwd == (n+1)/2 ) continue;
                if( __gcd(where+nwd, pot) == nwd*2 ) {
                    where += nwd;
                } else {
                    where -= nwd;
                }
            } else {
                if( nwd==1 ) continue;
                nwd/=2;
                if( c == 'L' ) {
                    where -= nwd;
                } else {
                    where += nwd;
                }
            }
        }
        cout << where << "\n";
    }

    return 0;
}