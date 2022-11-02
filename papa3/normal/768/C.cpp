#include<bits/stdc++.h>

using namespace std;

//#define int long long

int tab[1111], n, k, x;
int tab2[1111];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    cin >> n >> k >> x;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        tab[a]++;
    }
    int miniete=0;
    while( k-- ) {
        miniete = 0;
        for( int i=0; i<1024; i++ ) {
            if( tab[i]%2 == 1 ) {
                if( miniete%2==0 ) {
                    tab2[i^x] += tab[i]/2+1;
                    tab2[i] += tab[i]/2;
                } else {
                    tab2[i^x] += tab[i]/2;
                    tab2[i] += tab[i]/2+1;
                }
            } else {
                tab2[i^x] += tab[i]/2;
                tab2[i] += tab[i]/2;
            }
            miniete += tab[i];
        }
        for( int i=0; i<1024; i++ ) {
            tab[i] = tab2[i];
            tab2[i] = 0;
        }
    }
    for( int i=1023; i>=0; i-- ) {
        if( tab[i] ) {
            cout << i << " ";
            break;
        }
    }
    for( int i=0; i<1024; i++ ) {
        if( tab[i] ) {
            cout << i << " ";
            break;
        }
    }

}
/*
1125899906842624
*/