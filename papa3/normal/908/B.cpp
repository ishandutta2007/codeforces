#include<bits/stdc++.h>

using namespace std;

//#define int long long

pair<int, int> kier[] { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<int> per {0, 1, 2, 3};

char tab[100][100];
string s;
pair<int, int> start;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int i=0; i<n+5; i++ ) {
        for( int j=0; j<m+5; j++ ) {
            tab[i][j] = '#';
        }
    }
    for( int i=1; i<=n; i++ ) {
        for( int j=1; j<=m; j++ ) {
            cin >> tab[i][j];
            if( tab[i][j] == 'S' ) {
                start = {i, j};
            }
        }
    }
    cin >> s;

    int res=0;
    do {
        pair<int, int> gdzie = start;
        for( char c : s ) {
            int a = c-'0';
            gdzie = { gdzie.first+kier[ per[a] ].first, gdzie.second+kier[ per[a] ].second };
            if( tab[gdzie.first][gdzie.second] == '#' ) break;
            if( tab[gdzie.first][gdzie.second] == 'E' ) {
                res++;
                break;
            }
        }
    } while( next_permutation( per.begin(), per.end() ) );

    cout << res;

    return 0;
}