#include<bits/stdc++.h>

using namespace std;

#define int long long

int kolor[1000010];
vector<int> drogi[1000010];
int n, wy;

void init() {
    cin >> n;
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
}

void DFS( int gdzie=1, int skad=0 ) {
    int k=1;
    for( int i : drogi[gdzie] ) {
        if( kolor[i] == 0 ) {
            while( kolor[gdzie] == k || kolor[skad] == k ) {
                k++;
            }
            wy = max( k, wy );
            kolor[i] = k;
            DFS( i, gdzie );
            k++;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    init();
    kolor[1] = 1;
    DFS();
    cout << wy << "\n";
    for( int i=1; i<=n; i++ ) {
        cout << kolor[i] << " ";
    }

    return 0;
}