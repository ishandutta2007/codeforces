#include<bits/stdc++.h>

using namespace std;

#define int long long

bool czy[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    int res = 1;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        if( !czy[ a ] ) {
            czy[a] = 1;
        } else {
            res++;
        }
    }
    cout << res;
    return 0;
}