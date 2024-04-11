#include<bits/stdc++.h>

using namespace std;

int drogi[1000];
bool czy[1000];

int DFS( int pocz, int gdzie ) {
    czy[gdzie] = 1;
    if( czy[ drogi[gdzie] ] ) {
        if( drogi[gdzie] == pocz ) {
            return 1;
        } else {
            return -1;
        }
    } else {
        int y=DFS( pocz, drogi[gdzie] );
        if( y == -1 ) {
            return -1;
        } else {
            return 1+y;
        }
    }
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> drogi[i];
    }
    int nww=1;
    for( int x, i=1; i<=n; i++ ) {
        if( !czy[i] ) {
            x = DFS( i, i );
            if( x == -1 ) {
                cout << -1;
                return 0;
            }
            if( x%2 == 0 ) {
                x/=2;
            }
            nww = nww*x/__gcd( nww, x );
        }
    }
    cout << nww;

    return 0;
}