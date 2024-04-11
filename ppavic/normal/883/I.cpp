#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

const int N = 300005;

int n, k;
int P[N];
int dp[N];
int tree[N];

void add( int x, int val ) {
    for(++x ; x < N; x += x & -x ) tree[x] += val;
}

int query( int x ) {
    int sol = 0;
    for( ++x; x > 0; x -= x & -x ) sol += tree[x];
    return sol;
}

void load( ) {
	cin >> n >> k;
	for( int i = 1; i <= n; i++ ) scanf( "%d", P + i );
	sort( P + 1, P + n + 1 );
}

bool can(int x) {
    memset( dp, 0, sizeof(dp));
    memset( tree, 0, sizeof(tree) );
    add(0, 1);
    int ptr = 1;
    for( int i = 1; i <= n; i++ ) {
        while( ptr <= n && P[i] - P[ptr] > x ) ptr++;
        if( i - ptr + 1 >= k ) {
            //[ptr-1,i-k]
            int ans = query(i-k) - query(ptr - 2);
            if( ans != 0 ) dp[i] = 1;
        }

        add( i, dp[i] );
    }
    return dp[n];
}

void solve( ) {
   // printf( "can(20) == %d\n", can(19) );
    int low = 0, high = 1000000005, middle;
    while( low < high ) {
            middle = ( low + high) / 2;
            if( !can(middle) ) low = middle+1;
            else high = middle;
    }
    cout << low << endl;
}


int main( void ) {
	load();
	solve();
	return 0;
}