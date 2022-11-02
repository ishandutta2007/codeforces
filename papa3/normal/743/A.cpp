#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    a--;
    b--;
    if( s[a] == s[b] ) {
        cout << 0;
    } else {
        cout << 1;
    }

    return 0;
}