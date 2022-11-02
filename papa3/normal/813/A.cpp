#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    int sum=0;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        sum += a;
    }
    cin >> n;
    for( int i=1, a, b; i<=n; i++ ) {
        cin >> a >> b;
        if( b>=sum ) {
            cout << max( sum, a );
            return 0;
        }
    }
    cout << -1;

    return 0;
}/*
1
3
1
1 5
*/