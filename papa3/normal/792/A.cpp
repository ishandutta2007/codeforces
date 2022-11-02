#include<bits/stdc++.h>

using namespace std;

#define int long long

map<int, int> m;
map<int, int> res;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        m[a]++;
    }
    auto it=m.begin(), it2=m.begin();
    it++;
    for( ; it!=m.end(); it2++, it++ ) {
        res[ abs( it->first-it2->first ) ]++;
    }
    cout << res.begin()->first << " " << res.begin()->second;

    return 0;
}/*
2 2 3
1 2 3
2 1 3
*/