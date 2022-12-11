#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 1010;
int G[N];
int n, m;

int find( int x ) {
	if ( G[x] == x ) return x;
	return G[x] = find( G[x] );
}
int main() {

	ios::sync_with_stdio( false );

	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ ) {
		G[i] = i;
	}

	for ( int i = 0 ; i < m ; i++ ) {
		int u, v;
		cin >> u >> v;
		G[ find(u) ] = find(v);
	}

	bool err = ( m != n-1 );
	for ( int i = 2 ; i <= n ; i++ ) {
		if ( find(i) != find(1) ) {
			err = true;
		}
	}

	cout << ( err ? "no" : "yes" ) << endl;

	return 0;
}