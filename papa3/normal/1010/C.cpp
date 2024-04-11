#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll


int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, k;
    cin >> n >> k;
    int nwd = k;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        nwd = __gcd( a, nwd );
    }
    cout << k/nwd << "\n";
    for( int i=0; i<k; i+=nwd ) cout << i << " ";

    return 0;
}