#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll11

struct algo {
    int a, b;

    algo() {
        cin >> a >> b;
        if( a-b != 1 ) {
            cout << "NO\n";
            return;
        }
        a += b;
        int x = sqrt( a )+10;
        for( int i=2; i<=x && i<a; i++ ) {
            if( a%i == 0 ) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int t;
    cin >> t;
    while( t-- ) algo p;

    return 0;
}