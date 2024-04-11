#include<bits/stdc++.h>

using namespace std;

#define int long long

char kra[200];
int licz[200];

int wch[200];
bool ex[200];

string wy;

void wypisz( char i ) {
    wy.push_back( i );
    ex[i] = 0;
    if( kra[i] )
        wypisz( kra[i] );
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    string a;
    for( int i=1; i<=n; i++ ) {
        cin >> a;
        licz[ a.back() ]++;
        ex[ a.back() ] = 1;
        for( int i=0; i<a.size()-1; i++ ) {
            ex[ a[i] ] = 1;
            if( kra[ a[i] ] == 0 ) {
                kra[ a[i] ] = a[i+1];
                wch[ a[i+1] ]++;
            } else if( kra[ a[i] ] != a[i+1] ) {
                cout << "NO";
                return 0;
            }
            if( ++licz[ a[i] ] > 1 ) {
                cout << "NO";
                return 0;
            }
            if( wch[ a[i+1] ] > 1 ) {
                cout << "NO";
                return 0;
            }
        }
        for( char j = 'a'; j<='z'; j++ ) {
            licz[j] = 0;
        }
    }
    for( char i = 'a'; i<='z'; i++ ) {
        if( ex[i] && wch[i] == 0 ) {
            wypisz( i );
        }
    }
    for( char i = 'a'; i<='z'; i++ ) {
        if( ex[i] ) {
            cout << "NO";
            return 0;
        }
    }
    for( char i : wy ) {
        cout << i;
    }

    return 0;
}