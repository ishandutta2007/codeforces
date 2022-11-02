#include<bits/stdc++.h>

using namespace std;

int tab[30];

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    string a;
    cin >> a;
    int x, ile_zle=0;
    if( a.size() < 26 ) {
        cout << -1;
        return 0;
    }
    for( int i=0; i<26; i++ ) {
        if( a[i] != '?' ) {
            x = a[i] - 'A';
            tab[ x ]++;
            if( tab[ x ] == 2 ) {
                ile_zle++;
            }
        }
    }
    int start=-1;
    if( ile_zle == 0 ) {
        start = 0;
    } else {
        for( int i=26; i<a.size(); i++ ) {
            if( a[i] != '?' ) {
                x = a[i] - 'A';
                tab[ x ]++;
                if( tab[ x ] == 2 ) {
                    ile_zle++;
                }
            }
            if( a[i-26] != '?' ) {
                x = a[i-26] - 'A';
                tab[ x ]--;
                if( tab[ x ] == 1 ) {
                    ile_zle--;
                }
            }
            if( ile_zle == 0 ) {
                start = i-25;
                break;
            }
        }
    }
    if( start == -1 ) {
        cout << -1;
    } else {
        for( int i = 0; i<start; i++ ) {
            if( a[i] == '?' ) {
                cout << 'A';
            } else {
                cout << a[i];
            }
        }
        int p=0;
        char c;
        for( int i=start; i<start+26; i++ ) {
            if( a[i] == '?' ) {
                while( tab[p] != 0 ) {
                    p++;
                }
                c = p+'A';
                cout << c;
                p++;
            } else {
                cout << a[i];
            }
        }
        for( int i = start+26; i<a.size(); i++ ) {
            if( a[i] == '?' ) {
                cout << 'A';
            } else {
                cout << a[i];
            }
        }
    }
    return 0;
}
/*
AA?C?EFGHIJKLMNOPQRSTUVWXY?A

*/