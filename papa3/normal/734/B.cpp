#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    long long d, t, p, s, wy = 0;
    cin >> d >> t >> p >> s;
    long long x = min( d, min( p, s ) );
    wy += x*256;
    d -= x;
    cout << wy + min( d, t )*32;
    return 0;
}