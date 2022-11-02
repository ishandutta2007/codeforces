#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007LL
#define INF 1000000000000000000LL

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    vector<int> v;
    cin >> n;
    for( int a, i=0; i<2*n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    sort( v.begin(), v.end() );
    int res = (v[n-1]-v[0])*(v[2*n-1]-v[n]);
    for( int i=n; i<2*n; i++ ) {
        res = min( res, (v[2*n-1]-v[0])*(v[i]-v[i-n+1]) );
    }
    cout << res;

    return 0;
}
/*

*/