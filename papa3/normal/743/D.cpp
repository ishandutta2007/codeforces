#include<bits/stdc++.h>

using namespace std;

#define zak 200010

long long suma[zak], m1[zak], m2[zak], wy = -numeric_limits<long long>::max();
vector<int> drogi[zak];
bool czy[zak];

void DFS( int gdzie=1 ) {
    czy[gdzie] = 1;
    long long a = -numeric_limits<long long>::max(), b = -numeric_limits<long long>::max();
    for( int i : drogi[gdzie] ) {
        if( !czy[i] ) {
            DFS( i );
            suma[gdzie] += suma[i];
            if( m1[i] > a ) {
                b = a;
                a = m1[i];
            } else if( m1[i] > b ) {
                b = m1[i];
            }
        }
    }
    if( b != -numeric_limits<long long>::max() ) {
        wy = max( wy, a+b );
    }
    if( suma[gdzie] > a ) {
        b = a;
        a = suma[gdzie];
    } else if( suma[gdzie] > b ) {
        b = suma[gdzie];
    }
    m1[gdzie] = a;
    m2[gdzie] = b;
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> suma[i];
        m1[i] = m2[i] = -numeric_limits<long long>::max();
    }
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }

    DFS();
    if( wy == -numeric_limits<long long>::max() ) {
        cout << "Impossible";
    } else {
        cout << wy;
    }

    return 0;
}/*
4
-1 -1 -1 -1
1 2
1 3
2 4
*/