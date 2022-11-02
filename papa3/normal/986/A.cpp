#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

int odl[100010][110];
vector<int> drogi[100010];
int n;

void foo( int id ) {
    queue<int> kol;
    for( int i=1; i<=n; i++ ) {
        if( odl[i][id] == 0 ) kol.push( i );
    }
    int gdzie;
    while( !kol.empty() ) {
        gdzie = kol.front();
        kol.pop();
        for( int i : drogi[gdzie] ) {
            if( odl[i][id] == INF ) {
                odl[i][id] = odl[gdzie][id]+1;
                kol.push( i );
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int m, k, s;
    cin >> n >> m >> k >> s;
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=k; j++ ) {
            odl[i][j] = INF;
        }
    }
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        odl[i][a] = 0;
    }
    for( int a, b, i=1; i<=m; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
    for( int i=1; i<=k; i++ ) {
        foo( i );
    }
    for( int wy, i=1; i<=n; i++ ) {
        sort( odl[i]+1, odl[i]+k+1 );
        wy = 0;
        for( int j=1; j<=s; j++ ) {
            wy += odl[i][j];
        }
        cout << wy << " " ;
    }

    return 0;
}
/*

*/