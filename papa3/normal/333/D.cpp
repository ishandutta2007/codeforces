#include<bits/stdc++.h>

using namespace std;

//#define int long long

struct moj {
    int val, x, y;
    bool operator < ( const moj & other ) const {
        return val > other.val;
    }
};

vector<moj> v;
vector<int> tab[1010];
bool t[1010][1010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int i=1; i<=n; i++ ) {
        for( int a, j=1; j<=m; j++ ) {
            cin >> a;
            v.push_back( {a, i, j} );
        }
    }
    sort( v.begin(), v.end() );

    for( auto & i : v ) {
        for( int j : tab[i.y] ) {
            if( t[j][i.x] ) {
                cout << i.val;
                return 0;
            }
            t[j][i.x] = true;
            t[i.x][j] = true;
        }
        tab[i.y].push_back( i.x );
    }

    return 0;
}