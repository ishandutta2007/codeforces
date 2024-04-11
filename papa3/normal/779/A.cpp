#include<bits/stdc++.h>

using namespace std;

#define int long long

int tab[6], tab2[6];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        tab[a]++;
    }
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        tab2[a]++;
    }
    int wy=0;
    for( int i=1; i<=5; i++ ) {
        if( abs( tab[i]-tab2[i] )%2 == 1 ) {
            cout << -1;
            return 0;
        }
        wy += abs( tab[i]-tab2[i] )/2;
    }
    cout << wy/2;

    return 0;
}