#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
const long long mod = 1000000007ll;
const long long INF = 1000000000000000000ll;

int tab[20];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=0; i<n; i++ ) {
        cin >> tab[i];
    }

    for( int mask=0; mask<(1<<n); mask++ ) {
        int pos=0;
        for( int i=0; i<n; i++ ) {
            if( mask & (1<<i) ) pos += tab[i];
            else pos += 360-tab[i];
        }
        if( pos%360 == 0 ) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}/*

*/