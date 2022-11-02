#include<bits/stdc++.h>

using namespace std;

int tab[30][30];
int t[30];
int xx[30];

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, m;
    cin >> n >> m;
    for( int i=0; i<n; i++ ) {
        for( int j=0; j<m; j++ ) {
            cin >> tab[i][j];
        }
    }
    for( int i=0; i<m; i++ ) {
        tab[n][i] = i+1;
    }
    int ile_zmian;
    bool czy;
    ile_zmian = 0;
    czy = 1;
    for( int x=1; x<=n; x++ ) {
        ile_zmian = 0;
        for( int q=0; q<m; q++ ) {
            if( tab[0][q] != tab[x][q] ) {
                ile_zmian++;
            }
        }
        if( ile_zmian > 2 ) {
            czy = 0;
        }
    }

    if( czy ) {
        cout << "YES";
        return 0;
    }
    for( int i=0; i<m-1; i++ ) { // jeszce trza bez zmiany|!!!!!!
        for( int j=1; j<m; j++ ) {
            swap( tab[0][i], tab[0][j] );

            czy = 1;
            for( int x=1; x<=n; x++ ) {
                ile_zmian = 0;
                for( int q=0; q<m; q++ ) {
                    if( tab[0][q] != tab[x][q] ) {
                        ile_zmian++;
                    }
                }
                if( ile_zmian > 2 ) {
                    czy = 0;
                }
            }

            if( czy ) {
                cout << "YES";
                return 0;
            }

            swap( tab[0][i], tab[0][j] );
        }
    }
    cout << "NO";
    /*int ilezle;
    int x, y, a, b;
    bool czy = 1;
    for( int i=1; i<n; i++ ) {
        ilezle = 0;
        for( int j=0; i<m; j++ ) {
            if( tab[0][j] != tab[i][j] ) {
                ilezle++;
                if( ilezle == 1 ) {
                    x = j;
                } else if( ilezle == 2 ) {
                    y = j;
                } else {
                    cout << "NO";
                    return 0;
                }
            }
        }
        if( i==1 ) {
            a = x;
            b = y;
        } else {
            if( ilezle ) {
                if( x == a && y == b ) {
                    continue;
                }

            }
        }
    }*/
    return 0;
}