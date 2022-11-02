#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 998244353ll
#define INF 1000000000000000000ll

vector<int> drogi[1000010];
int dist[2][1000010];

void dfs( int gdzie, int skad, int id ) {
    for( int i : drogi[gdzie] ) {
        if( i==skad ) continue;
        dist[id][i] = dist[id][gdzie]+1;
        dfs( i, gdzie, id );
    }
}

int k;

bool spr( int gdzie, int skad, int odl=0 ) {
    if( odl>k ) return 0;
    if( drogi[gdzie].size() == 1 && odl != k ) return 0;
    for( int i : drogi[gdzie] ) {
        if( skad == i ) continue;
        if( !spr( i, gdzie, odl+1 ) ) return 0;
    }
    return 1;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n >> k;
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        drogi[b].push_back( a );
    }

    int ile=0;

    int gdzie = 0;
    for( int i=1; i<=n; i++ ) {
        if( drogi[i].size() == 1 ) {
            gdzie = i;
        }
        if( drogi[i].size() == 2 ) {
            cout << "No";
            return 0;
        }
        if( drogi[i].size() == 3 ) ile++;
    }
    if( ile>1 ) {
        cout << "No";
        return 0;
    }

    dfs( gdzie, gdzie, 0 );
    int pom=1;
    for( int i=1; i<=n; i++ ) {
        if( dist[0][i] == 2*k ) {
            pom = i;
        }
    }
    dfs( pom, pom, 1 );
    for( int i=1; i<=n; i++ ) {
        if( dist[0][i] == k && dist[1][i] == k ) {
            if( ile && drogi[i].size() != 3 ) {
                cout << "No";
                return 0;
            }
            if( spr( i, i ) ) {
                cout << "Yes";
            } else {
                cout << "No";
            }
            return 0;
        }
    }
    cout << "No";

    return 0;
}/*

*/