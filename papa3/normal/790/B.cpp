#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> drogi[200010];
int n, k;
int ile[7][200010], wy;
int ile2[7][200010];
bool czy[200010];
bool czy2[200010];
int res[7][200010];

void algo( int gdzie ) {
    czy[gdzie] = true;
    for( int i : drogi[gdzie] ) {
        if( !czy[i] ) {
            algo( i );
            for( int j=0; j<k; j++ ) {
                for( int x=0; x<k; x++ ) {
                    if( x==1 || k==1 ) {
                        wy += res[j][gdzie]*ile[(x+k-1)%k][i];
                        wy += (res[(x+k-1)%k][i]+ile[(x+k-1)%k][i])*ile[j][gdzie];
                    } else {
                        wy += res[j][gdzie]*ile[(x+k-1)%k][i];
                        wy += res[(x+k-1)%k][i]*ile[j][gdzie];
                    }
                    if( x != 0 && j!= 0 && j+x<=k ) {
                        wy -= ile[j][gdzie]*ile[(x+k-1)%k][i];
                    }
                }
            }
            //wy++;
            for( int j=0; j<k; j++ ) {
                ile[(j+1)%k][gdzie] += ile[j][i];
                if( j != 0 ) {
                    res[(j+1)%k][gdzie] += res[j][i];
                    wy += res[j][i];
                } else {
                    res[(j+1)%k][gdzie] += res[j][i]+ile[j][i];
                    wy += res[j][i]+ile[j][i];
                }
            }
        }
    }
    ile[0][gdzie]++;
}

/*void algo( int gdzie ) {
    czy[gdzie] = true;
    for( int i : drogi[gdzie] ) {
        if( !czy[i] ) {
            algo( i );
            for( int j=0; j<k; j++ ) {
                ile[(j+1)%k][gdzie] += ile[j][i];
            }
        }
    }
    ile[0][gdzie]++;
}

void dfs( int gdzie ) {
    czy2[gdzie] = true;
    for( int i : drogi[gdzie] ) {
        if( !czy2[i] ) {
            dfs( i );
            for( int j=0; j<k; j++ ) {
                ile2[j+1][gdzie] += ile2[j][i];
            }
        }
    }
    for( int j=1; j<=k; j++ ) {
        wy += ile2[j][gdzie];
    }
    ile2[0][gdzie]=1;
}*/

void init() {
    cin >> n >> k;
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
    algo( 1 );
    //dfs( 1 );
    cout << wy;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    init();

    return 0;
}/*
4 1
1 2
1 3
1 4
*/