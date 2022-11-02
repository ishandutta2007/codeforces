#include<bits/stdc++.h>

using namespace std;

int tab[26];
char jaki;
int pocz=-1, kon;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    string s, wy1, wy2;
    cin >> s;
    for( int i=0; i<27; i++ ) {
        tab[ s[i]-'A' ]++;
        if( tab[ s[i]-'A' ] == 2 ) {
            jaki = s[i];
        }
    }
    for( int i=0; i<27; i++ ) {
        if( s[i] == jaki ) {
            if( pocz == -1 ) {
                pocz = i;
            } else {
                kon = i;
            }
        }
    }
    if( kon-pocz == 1 ) {
        cout << "Impossible";
        return 0;
    }
    int sr = (kon-pocz-1);
    int boki = 27-sr-2;
    wy1 = s[pocz];
    for( int i=0; i<sr/2; i++ ) {
        wy1 = wy1+s[pocz+1+i];
    }
    for( int i=0, j=pocz-1; i<boki/2; i++, j-- ) {
        if( j<0 ) {
            j=26;
        }
        wy1 = s[j] + wy1;
    }
    cout << wy1;
    for( int i=0, j=pocz-1-boki/2; i<(boki+1)/2; i++, j-- ) {
        if( j<0 ) {
            j+=27;
        }
        wy2 = wy2+s[j];
    }
    for( int i=0, j=kon-1; i<(sr+1)/2; i++, j-- ) {
        wy2 = wy2+s[j];
    }
    cout << "\n" << wy2;
    return 0;
}