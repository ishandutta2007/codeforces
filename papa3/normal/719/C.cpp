#include<bits/stdc++.h>

using namespace std;

vector<char> v;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, t;
    char x;
    cin >> n >> t;
    v.push_back( '0' );
    for( int i=0; i<n; i++ ) {
        cin >> x;
        v.push_back( x );
    }
    bool zwieksz=0, czy=0;
    int gdzie=-1;
    for( int i=0; i<=n; i++ ) {
        if( v[i] == '.' ) {
            czy = 1;
        }
        if( czy && v[i] >= '5' ) {
            gdzie = i-1;
            n=i-1;
            zwieksz = 1;
            break;
        }
    }

    if( zwieksz ) {
        if( gdzie != -1 ) {
            while( t ) {
                while( zwieksz ) {
                    if( v[gdzie] == '.' ) {
                        czy = 0;
                        n = gdzie-1;
                    }
                    if( v[gdzie] != '.' && v[gdzie] != '9' ) {
                        v[gdzie]++;
                        zwieksz = 0;
                        if( czy )
                            n = gdzie;
                    } else {
                        v[gdzie]='0';
                        gdzie--;
                    }
                }
                t--;
                if( v[gdzie] >= '5' && czy ) {
                    zwieksz = 1;
                    gdzie--;
                } else {
                    break;
                }
            }
        }
    }
    if( v[0] != '0' ) {
        cout << v[0];
    }
    for( int i=1; i<=n; i++ ) {
        cout << v[i];
    }
    return 0;
}