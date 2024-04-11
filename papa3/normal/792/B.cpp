#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> v, jak;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, k;
    cin >> n >> k;
    for( int a, i=0; i<k; i++ ) {
        cin >> a;
        jak.push_back( a );
    }
    for( int i=1; i<=n; i++ ) {
        v.push_back( i );
    }
    int gdzie = 0;
    for( int i : jak ) {
        gdzie = (gdzie+i)%v.size();
        cout << v[gdzie] << " ";
        v.erase( v.begin()+gdzie );
    }

    return 0;
}/*
2 2 3
1 2 3
2 1 3
*/