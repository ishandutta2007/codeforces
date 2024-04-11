#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int a;
    cin >> a;
    if( a == 1 ) {
        cout << "1 1\n1";
    } else {
        cout << a*2-2 << " 2" << "\n";
        cout << "1 2";
    }

    return 0;
}