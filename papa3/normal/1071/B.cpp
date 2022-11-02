#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

char tab[2010][2010];
int dist[2010][2010];
bool czy[2010][2010];
char res[1000000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, k;
    cin >> n >> k;

    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=n; j++ ) {
            cin >> tab[i][j];
            dist[i][j] = INF;
        }
    }

    if( k ) {
        deque<pair<int, int> > kol;
        czy[1][1] = 1;
        dist[1][1] = 0;
        if( tab[1][1] != 'a' ) {
            tab[1][1] = 'a';
            dist[1][1] = 1;
        }
        int x, y;
        kol.push_back( {1, 1} );
        while( !kol.empty() ) {
            x = kol.front().first;
            y = kol.front().second;
            kol.pop_front();
            if( dist[x][y] == k ) continue;
            if( x>n || y>n ) continue;
            if( !czy[x+1][y] ) {
                czy[x+1][y] = 1;
                dist[x+1][y] = dist[x][y];
                if( tab[x+1][y] != 'a' ) {
                    tab[x+1][y] = 'a';
                    dist[x+1][y]++;
                    kol.push_back( {x+1, y} );
                } else {
                    kol.push_front( {x+1, y} );
                }
            }
            if( !czy[x][y+1] ) {
                czy[x][y+1] = 1;
                dist[x][y+1] = dist[x][y];
                if( tab[x][y+1] != 'a' ) {
                    tab[x][y+1] = 'a';
                    dist[x][y+1]++;
                    kol.push_back( {x, y+1} );
                } else {
                    kol.push_front( {x, y+1} );
                }
            }
        }
    }

    for( int i=0; i<=2*n; i++ ) res[i] = 'z';
    for( int i=0; i<=n; i++ ) {
        for( int j=0; j<=n; j++ ) {
            czy[i][j] = 0;
        }
    }
    queue<pair<int, int> > kol;
    res[2] = tab[1][1];
    kol.push( {1, 1} );
    int x, y;
    while( !kol.empty() ) {
        x = kol.front().first;
        y = kol.front().second;
        kol.pop();
        if( tab[x][y] > res[x+y] ) continue;
        if( !czy[x+1][y] && x<n ) {
            res[x+y+1] = min( res[x+y+1], tab[x+1][y] );
            czy[x+1][y] = 1;
            kol.push( {x+1, y} );
        }
        if( !czy[x][y+1] && y<n ) {
            res[x+y+1] = min( res[x+y+1], tab[x][y+1] );
            czy[x][y+1] = 1;
            kol.push( {x, y+1} );
        }
    }

    for( int i=2; i<=2*n; i++ ) cout<< res[i];

    return 0;
}/*

*/