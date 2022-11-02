#include<bits/stdc++.h>

using namespace std;

#define int long long

int t1[1000], t2[1000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        if( a == 0 ) {
            t2[i]++;
        } else {
            t1[i]++;
        }
        t1[i] += t1[i-1];
    }
    for( int i=n; i>=0; i-- ) {
        t2[i] += t2[i+1];
    }
    int res = 0;
    for( int i=0; i<=n; i++ ) {
        res = max( res, n-t1[i]-t2[i+1] );
    }
    cout << res;
    return 0;
}