#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    int p, q, b;
    int x;
    while( n-- ) {
        cin >> p >> q >> b;
        if( p==0 ) {
            cout << "Finite\n";
            continue;
        }
        x = __gcd( p, q );
        q /= x;

        x=b;
        do {
            x = __gcd( q, x );
            q/=x;
        } while( x!=1 );
        if( q == 1 ) {
            cout << "Finite\n";
        } else {
            cout << "Infinite\n";
        }
    }

    return 0;
}
/*

*/