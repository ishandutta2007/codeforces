#include<bits/stdc++.h>

using namespace std;

bool tab[1010][1010];

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
    int ile;
    int wy=0;
    bool czy;
    for( int i=0; i<n; i++ ) {
        czy = false;
        for( int j=0; j<m; j++ ) {
            if( tab[i][j] ) {
                czy = true;
            } else if( czy ) {
                wy++;
            }
        }
    }
    for( int i=0; i<n; i++ ) {
        czy = false;
        for( int j=m-1; j>=0; j-- ) {
            if( tab[i][j] ) {
                czy = true;
            } else if( czy ) {
                wy++;
            }
        }
    }
    for( int j=0; j<m; j++ ) {
        czy = false;
        for( int i=0; i<n; i++ ) {
            if( tab[i][j] ) {
                czy = true;
            } else if( czy ) {
                wy++;
            }
        }
    }
    for( int j=0; j<m; j++ ) {
        czy = false;
        for( int i=n-1; i>=0; i-- ) {
            if( tab[i][j] ) {
                czy = true;
            } else if( czy ) {
                wy++;
            }
        }
    }
    cout << wy;
    return 0;
}