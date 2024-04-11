#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

int t[12321];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    cin >> s;
    for( int i=0; i<s.size(); i++ ) {
        t[s[i]]++;
        if( i>0 ) {
            if( s[i] != s[i-1] ) {
                if( s[i] == 'a' ) {
                    cout << "NO\n";
                    return 0;
                } else if( s[i] == 'c' && s[i-1] == 'a' ) {
                    cout << "NO\n";
                    return 0;
                } else if( s[i] == 'b' && s[i-1] == 'c' ) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    if( ( t['c'] == t['a'] || t['c'] == t['b'] ) && t['a'] && t['b'] ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
/*

*/