#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double


int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    cin >> s;

    char c='a';
    for( int i=0; i<s.size(); i++ ) {
        if( s[i] <= c ) {
            s[i] = c;
            if( c=='z' ) {
                cout << s;
                return 0;
            }
            c++;
        }
    }
    cout << -1;

    return 0;
}
//aaaaaaaaaaaaaaaaaaaaaaaaaa