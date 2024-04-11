#include<bits/stdc++.h>

using namespace std;

int tab[1000000];

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    int n, x;
    cin >> n >> x;
    int wy=0;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        if( x == i ) {
            if( a != 0 ) {
                wy++;
            }
            tab[0]++;
        } else {
            tab[a]++;
        }
    }
    int pocz=0, kon=n;
    while( tab[kon] == 0 ) {
        kon--;
    }
    while( pocz < kon ) {
        if( tab[pocz] == 0 ) {
            if( tab[0] > 1 ) {
                tab[pocz] = 1;
                tab[0]--;
                wy++;
            } else {
                tab[kon]--;
                tab[pocz]=1;
                wy++;
            }
        }
        while( tab[kon] == 0 ) {
            kon--;
        }
        pocz++;
    }
    cout << wy+tab[0]-1;
    return 0;
}