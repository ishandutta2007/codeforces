#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int l, r, t;
int ll, rr, tt;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );


    cin >> l >> r >> t >> ll >> rr >> tt;
    int nwd = __gcd( t, tt );

    int x = (nwd*1000000000ll+l-ll)%nwd;

    int d = r-l+1;
    int dd = rr-ll+1;
    l = ll+x;
    int res = max( 0ll, min( l+d, ll+dd )-max( l, ll ) );
    l -= nwd;
    int ress = max( 0ll, min( l+d, ll+dd )-max( l, ll ) );
    cout << max( res, ress );
    return 0;
}/*

*/