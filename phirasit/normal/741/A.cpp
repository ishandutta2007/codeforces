#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

vector< int > arr;
int pass[ N ];

int dfs( int u ) {
	if ( pass[u-1] ) return 0;
	pass[u-1] = 1;
	return dfs( arr[u-1] ) + 1;
}
int main( void ) {

	cin.sync_with_stdio( false );
	cin.tie( 0 );

	int n;
	cin >> n;

	arr.resize( n );
	for ( int &val : arr  ) {
		cin >> val;
		pass[ val ] = 1;
	}

	int err = false;
	for ( int i = 1 ; i <= n ; ++i ) {
		if ( !pass[i] ) {
			err = true;
		}
	}

	if ( err ) {
		cout << -1 << endl;
		return 0;
	}

	long long ans = 1ll;
	for ( int i = 1 ; i <= n ; ++i ) {
		pass[i] = 0;
	}

	for ( int i = 1 ; i <= n ; ++i ) {
		long long c = dfs( i );
		if ( c == 0 ) continue;
		if ( c % 2 == 0 ) c /= 2;
		ans = ( ans * c ) / __gcd( ans, c );
	}

	cout << ans << endl;

	return 0;
}