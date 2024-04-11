#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

vector<string> v[1000];
int ile[1000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    cin >> s;

    string pom;
    for( int i=0; i<s.size(); i++ ) {
        pom.clear();
        for( int j=i, k=0; k<s.size(); k++, j=(j+1)%s.size() ) {
            pom.push_back( s[j] );
        }
        v[ pom[0] ].push_back( pom );
    }

    int res=0;
    int x, y;
    for( char c='a'; c<='z'; c++ ) {
        y = 0;
        for( int i=1; i<s.size(); i++ ) {
            x=0;
            for( string & j : v[c] ) {
                ile[ j[i] ]++;
                if( ile[ j[i] ] == 1 ) x++;
                if( ile[ j[i] ] == 2 ) x--;
            }
            y = max( y, x );
            for( string & j : v[c] ) {
                ile[ j[i] ] = 0;
            }
        }
        res+=y;
    }

    cout << fixed << setprecision( 10 ) << (double)res / (double)s.size();

    return 0;
}