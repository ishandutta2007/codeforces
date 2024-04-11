#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    while( n-- ) {
        int a, b;
        cin >> a >> b;
        int x = a*b;
        int pocz = 1, kon = 1000010ll, sr;
        while( kon-pocz > 1 ) {
            sr = (pocz+kon)/2;
            if( sr*sr*sr <= x ) {
                pocz = sr;
            } else {
                kon = sr;
            }
        }
        if( pocz*pocz*pocz != x ) {
            cout << "No\n";
            continue;
        }
        if( a%pocz==0 && b%pocz==0 ) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}