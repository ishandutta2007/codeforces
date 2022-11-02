#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double


int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    int res=0;
    cin >> n;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        res+=abs(a);
    }
    cout << res;

    return 0;
}