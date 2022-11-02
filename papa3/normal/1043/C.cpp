#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int tab[10010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    cin >> s;
    for( int i=1; i<s.size(); i++ ) {
        if( s[i] == 'a' ) {
            tab[i] ^= 1;
            tab[i-1] ^= 1;
        }
    }
    for( int i=0; i<s.size(); i++ ) {
        cout << tab[i] << " ";
    }

    return 0;
}/*

*/