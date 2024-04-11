#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007
vector<int> v;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    int x=sqrt(n);
    for( int i=1; i<=n; i++ ) {
        v.push_back( i );
    }
    for( int i=0; i<n; i+=x ) {
        reverse( v.begin()+i, min(v.begin()+i+x, v.end()) );
    }
    for( int i : v ) cout << i << " ";


    return 0;
}
/*

*/