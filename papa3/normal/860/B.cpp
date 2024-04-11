#include<bits/stdc++.h>

using namespace std;

#define int long long

map<string, int> m;
vector<string> v;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        string s, x;
        set<string> se;
        cin >> s;
        v.push_back( s );
        for( int i=0; i<9; i++ ) {
            x = "";
            for( int j=i; j<9; j++ ) {
                x.push_back( s[j] );
                if( se.find( x ) == se.end() ) {
                    se.insert( x );
                    m[x]++;
                    //cout << x << "\n";
                }
            }
        }
    }
    for( int i=0; i<n; i++ ) {
        string s=v[i], x, wy="1111111111";
        for( int i=0; i<9; i++ ) {
            x = "";
            for( int j=i; j<9; j++ ) {
                x.push_back( s[j] );
                if( x.size() >= wy.size() ) break;
                if( m[x] == 1 )
                    wy = x;
            }
        }
        cout << wy << "\n";
    }


    return 0;
}