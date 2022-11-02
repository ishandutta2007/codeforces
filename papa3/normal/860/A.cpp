#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    cin >> s;
    int ile=0;
    char a=0, b=0;
    for( char c : s ) {
        if( c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' ) {
            cout << c;
            a=b=0;
            ile=0;
            continue;
        }
        if( ile==0 ) a=c;
        else if( a!=c ) b=c;
        ile++;
        if( ile>2 && b ) {
            cout << " ";
            a=b=0;
            a=c;
            ile=1;
        }
        cout << c;
    }

    return 0;
}