#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double


int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int a, b;
    cin >> a >> b;

    while( a!=0 && b!=0 ) {
        if( a>=2*b ) {
            int x= a/(2*b);
            a -= x*2*b;
        } else if( b>=2*a ) {
            int x= b/(2*a);
            b -= x*2*a;
        } else {
            break;
        }
    }
    cout << a << ' ' << b;

    return 0;
}