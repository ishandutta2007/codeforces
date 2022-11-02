#include<bits/stdc++.h>

using namespace std;

bool pom[200010], odw[200010];
int j, d, odl[200010], maks, pocz=1;
vector<int> drogi[200010];

void DFS( int gdzie ) {
    odw[gdzie] = true;
    for( int i : drogi[gdzie] ) {
        if( !odw[i] ) {
            if( pom[i] != pom[gdzie] ) {
                odl[i] = odl[gdzie]+1;
                if( odl[i] > maks ) {
                    maks = odl[i];
                    pocz = i;
                }
            } else {
                odl[i] = odl[gdzie];
            }
            DFS( i );
        }
    }
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> pom[i];
    }
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }
    DFS( 1 );
    for( int i=1; i<=n; i++ ) {
        odw[i] = 0;
    }
    odl[pocz] = 1;
    maks = 1;
    DFS( pocz );
    cout << maks/2;
    return 0;
}