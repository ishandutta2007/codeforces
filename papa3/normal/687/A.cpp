#include<bits/stdc++.h>

using namespace std;

vector<int> drogi[100010];
vector<int> wy[4];
int nr[100010];
bool czy;

void DFS( int gdzie, int n=2 ) {
    nr[gdzie] = n;
    wy[n].push_back( gdzie );
    for( int & i : drogi[gdzie] ) {
        if( nr[i] == 0 ) {
            DFS( i, n^1 );
        } else if( nr[i] == n ) {
            czy = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, m;
    cin >> n >> m;
    for( int a, b, i=0; i<m; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
    for( int i=1; i<=n; i++ ) {
        if( nr[i] == 0 ) DFS( i );
    }
    if( czy ) {
        cout << -1;
    } else {
        cout << wy[2].size() << "\n";
        for( int & i : wy[2] ) {
            cout << i << " ";
        }
        cout << "\n" << wy[3].size() << "\n";
        for( int & i : wy[3] ) {
            cout << i << " ";
        }
    }

    return 0;
}