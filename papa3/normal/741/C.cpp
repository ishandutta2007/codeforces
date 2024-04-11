#include<bits/stdc++.h>

using namespace std;

vector<int> drogi[1000010];
pair<int, int> wy[1000010];
int czy[1000010];

void DFS( int gdzie, int nr=2 ) {
    czy[gdzie] = nr-1;
    for( int & i : drogi[gdzie] ) {
        if( czy[i] == 0 ) {
            DFS( i, nr^1 );
        }
    }
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int a, b, i=0; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
        wy[i] = {a, b};
    }
    for( int i=1; i<=2*n; i+=2 ) {
        drogi[i].push_back( i+1 );
        drogi[i+1].push_back( i );
    }
    for( int i=1; i<=2*n; i++ ) {
        if( czy[i] == 0 ) {
            DFS( i );
        }
    }
    for( int i=0; i<n; i++ ) {
        cout << czy[ wy[i].first ] << " " << czy[ wy[i].second ] << "\n";
    }

    return 0;
}