#include<bits/stdc++.h>

using namespace std;

int odl[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    queue<int> kol;
    int n, k;
    cin >> n >> k;
    for( int i=1; i<=k; i++ ) {
        kol.push( 1 );
    }

    int li = 1;

    vector<pair<int, int> > wy;
    pair<int, int> p {0, 10};

    while( li < n ) {
        li++;
        wy.push_back( {kol.front(), li} );
        odl[li] = odl[kol.front()]+1;
        if( odl[li] > p.first ) {
            p = {odl[li], 1};
        } else if( odl[li] == p.first ) p.second++;
        kol.push( li );
        kol.pop();
    }
    if( p.second == 1 ) {
        cout << p.first*2-1 << "\n";
    } else {
        cout << p.first*2 << "\n";
    }
    for( auto i : wy ) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}