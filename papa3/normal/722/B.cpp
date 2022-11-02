#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    int licz;
    cin >> n;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    string s = "a";
            getline( cin, s );

    for( int i=0; i<n; i++ ) {
        getline( cin, s );

        licz = 0;
        for( char & x : s ) {
            if( x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y' ) {
                licz++;
            }
        }
        if( licz != v[i] ) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}