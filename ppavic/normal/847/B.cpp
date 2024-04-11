#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <string>
using namespace std;

const int N = 200005;

#define pb push_back
map<int,int> chain;

int n;
int P[N];
vector<int> V;

const int INF = 0x3f3f3f3f;

int cnt_lanac;
vector<int> E[N];
set<int> S;

void load( ) {
    scanf( "%d", &n );

    for( int i = 0; i < n; i++ ) scanf( "%d", P + i ), V.pb(P[i]);
}

void solve( ) {
    E[cnt_lanac].pb( P[0] );
    S.insert(P[0]);
    chain[P[0]] = cnt_lanac;

    for( int i = 1; i < n; i++ ) {
            set<int>::iterator it = S.upper_bound(P[i]);
            if( it == S.begin() ) {
                    E[++cnt_lanac].pb(P[i]);
                    S.insert(P[i]);
                    chain[P[i]] = cnt_lanac;
            } else {
                it--;
                int which = chain[*it];
                E[which].pb(P[i]);
                S.erase( it );
                S.insert( P[i] );
                chain[P[i]] = which;
            }

    }
    for( int i = 0; i <= cnt_lanac; i++ ) {
            for( int j = 0; j < E[i].size(); j++ ) printf( "%d ", E[i][j] );
            printf( "\n" );
    }
}


int main( void ) {
    load( );
    solve( );
    return 0;
}