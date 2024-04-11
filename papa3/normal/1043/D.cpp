#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int gdzie[12][100010];
int   tab[12][100010];
bool visited[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int i=1; i<=m; i++ ) {
        for( int a, j=1; j<=n; j++ ) {
            cin >> a;
            gdzie[i][a] = j;
            tab[i][j] = a;
        }
    }

    int pos[12];
    int res=0;
    for( int a=1; a<=n; a++ ) {
        int i = tab[1][a];
        if( visited[i] ) continue;
        for( int j=1; j<=m; j++ ) {
            pos[j] = gdzie[j][i];
        }
        int ile = 1;
        while( 1 ) {
            bool czy=1;
            for( int j=1; j<=m; j++ ) {
                if( ++pos[j] > n ) {
                    czy = 0;
                    break;
                }
                if( j>1 ) {
                    if( tab[j-1][ pos[j-1] ] != tab[j][ pos[j] ] ) {
                        czy = 0;
                        break;
                    }
                }
            }
            if( czy==0 ) break;
            visited[ tab[1][pos[1]] ] = 1;
            ile++;
        }
        res += (ile*(ile+1))/2;
    }
    cout << res;

    return 0;
}/*

*/