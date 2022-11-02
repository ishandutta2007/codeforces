#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 100000000000000000011

char tab[2010][2010];
bool czy[2010][2010];
pair<int, int> res[2010][2010];

pair<int, int> kier[] { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;

    for( int i=0; i<=n+1; i++ )
        for( int j=0; j<=m+1; j++ ) {
            tab[i][j] = '*';
        }
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=m; j++ ) {
            cin >> tab[i][j];
        }
    }

    deque<pair<int, int> > kol;
    czy[r][c] = 1;
    kol.push_back( {r, c} );
    while( !kol.empty() ) {
        int a = kol.front().first;
        int b = kol.front().second;
        kol.pop_front();

        for( pair<int, int> i : kier ) {
            if( czy[a+i.first][b+i.second] == 0 && tab[a+i.first][b+i.second] == '.' ) {
                czy[a+i.first][b+i.second] = 1;
                if( i.second ) kol.push_back( {a+i.first, b+i.second} );
                else kol.push_front( {a+i.first, b+i.second} );
                res[a+i.first][b+i.second] = res[a][b];
                if( i.second == 1 ) res[a+i.first][b+i.second].second++;
                if( i.second == -1 ) res[a+i.first][b+i.second].first++;
            }
        }
    }

    int wy=0;
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=m; j++ ) {
            if( czy[i][j] && res[i][j].first <= x && res[i][j].second <= y && tab[i][j] == '.' ) {
                //cout << "+";
                wy++;
            } //else cout << tab[i][j];
        }
        //cout << endl;
    }
    cout << wy;

    return 0;
}/*

*/