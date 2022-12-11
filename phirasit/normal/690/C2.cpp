#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 100010;

vector<int> adj[N];
int n, m;

pair<int, int> dp ( int u, int p ) {
	int ans1 = 0, ans2 = 0;
	int mx1 = 0, mx2 = 0;
	for ( int v : adj[u] ) {
		if ( v == p ) continue;
		auto res = dp( v, u );
		ans1 = max( ans1, res.first );
		if ( res.second > mx1 ) {
			mx2 = mx1;
			mx1 = res.second;
		} else if ( res.second > mx2 ) {
			mx2 = res.second;
		}
	}
	ans2 = mx1;
	ans1 = max( ans1, mx1 + mx2 + 1 );
	return { ans1, ans2 + 1 };
}
int main() {

	ios::sync_with_stdio( false );

	cin >> n >> m;
	for ( int i = 0 ; i < m ; i++ ) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back( v );
		adj[v].push_back( u );
	}

	cout << dp( 1, -1 ).first-1 << endl;

	return 0;
}