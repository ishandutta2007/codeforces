#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m, k;
vector<int> drogi[1000010], res[1000010];
bool czy[1000010];
int ile;

void init() {
    cin >> n >> m >> k;
    for( int a, b, i=1; i<=m; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
    ile = (2*n-1)/k+1;
}

int nr=1;

void DFS( int gdzie=1 ) {
    czy[gdzie] = 1;
    if( res[nr].size() == ile ) {
        nr++;
    }
    res[nr].push_back( gdzie );
    for( int i : drogi[gdzie] ) {
        if( !czy[i] ) {
            DFS( i );
            if( res[nr].size() == ile ) {
                nr++;
            }
            res[nr].push_back( gdzie );
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    init();
    DFS();
    for( int i=1; i<=k; i++ ) {
        if( res[i].size() == 0 ) {
            cout << "1 1\n";
            continue;
        }
        cout << res[i].size() << " ";
        for( int j : res[i] ) {
            cout << j << " ";
        }
        cout << "\n";
    }


    return 0;
}
/*
3 3 1
1 2
2 3
1 3
*/