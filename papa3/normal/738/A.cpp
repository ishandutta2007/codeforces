#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    string s, wy;
    int n;
    cin >> n >> s;
    s.push_back( 'x' );
    s.push_back( 'x' );
    s.push_back( 'x' );
    int i=0;

    while( i<n ) {
        if( s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o' ) {
            i+=3;
            while( s[i] == 'g' && s[i+1] == 'o' ) {
                i+=2;
            }
            wy.push_back( '*' );
            wy.push_back( '*' );
            wy.push_back( '*' );
        } else {
            wy.push_back( s[i] );
            i++;
        }
    }
    cout << wy;
    return 0;
}