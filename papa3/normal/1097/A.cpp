#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
const long long mod = 1000000007ll;
const long long INF = 1000000000000000000ll;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    char a, b;
    cin >> a >> b;
    char c, d;
    for( int i=1; i<=5; i++ ) {
        cin >> c >> d;
        if( c==a || d==b ) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}/*

*/