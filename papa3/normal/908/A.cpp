#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    cin >> s;
    int res = 0;
    for( char c : s ) {
        int a = c-'0';
        if( c == 'a' || c== 'e' || c == 'i' || c == 'o' || c == 'u' || ( a%2 && c>='0' && c<='9' ) ) {
            res++;

        }
    }
    cout << res;
    return 0;
}