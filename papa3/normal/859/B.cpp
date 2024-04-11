#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    int wy = numeric_limits<int>::max();
    for( int a, i=1; i<=1000000; i++ ) {
        a = ((n-1)/i)+1;
        wy = min( wy, 2*(i+a) );
    }
    cout << wy;

    return 0;
}