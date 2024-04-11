#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007
int x1, x2, y1, y2;
int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;

    for( int i=0; i<n; i++ ) {
        if( a[i] == '0' ) x1++;
        else y1++;
        if( b[i] == '1' ) continue;
        if( a[i] == '0' )  x2++;
        else y2++;
    }
    cout << x1*y2+x2*y1-x2*y2;

    return 0;
}
/*

*/