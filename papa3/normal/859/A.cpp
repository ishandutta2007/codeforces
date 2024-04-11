#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int k;
    cin >> k;
    int a;
    vector<int> v;
    for( int i=1; i<=k; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    sort( v.begin(), v.end() );
    cout << max( 0ll, *v.rbegin()-25 );

    return 0;
}