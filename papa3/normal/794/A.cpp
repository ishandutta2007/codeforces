#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int a, b, c;
    cin >> a >> b >> c;
    int n, res=0;
    cin >> n;
    for( int x, i=1; i<=n; i++ ) {
        cin >> x;
        if( x > b && x < c ) {
            res++;
        }
    }
    cout << res;

    return 0;
}