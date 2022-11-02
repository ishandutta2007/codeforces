#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll11

bool tab[1010][1010];
pair<int, int> kier[] { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
int x, y;
int a, b;
bool dfs( int xx, int yy ) {
    if( tab[xx][yy] ) return false;
    if( xx==a && yy==b ) return true;
    tab[xx][yy] = true;
    if( xx == x ) return 0;
    if( yy == y ) return 0;
    if( xx+yy == x+y ) return 0;
    if( xx-yy == x-y ) return 0;
    for( int i=-1; i<=1; i++ ) {
        for( int j=-1; j<=1; j++ ) {
            if( dfs( xx+i, yy+j ) ) return true;
        }
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;

    for( int i=0; i<n+2; i++ ) {
        for( int j=0; j<n+2; j++ ) tab[i][j] = 1;
    }
    for( int i=1; i<n+1; i++ ) {
        for( int j=1; j<n+1; j++ ) tab[i][j] = 0;
    }

    cin >> x >> y;
    int xx, yy;
    cin >> xx >> yy;

    cin >> a >> b;

    if( dfs( xx, yy ) ) cout << "YES\n";
    else cout << "NO";

    return 0;
}