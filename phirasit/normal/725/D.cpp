#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

const long long N = 300010;

multiset< long long > data1, data2;
long long B[ N ], W[ N ];
int n;

int idx[ N ];

int main( void ) {

	cin.sync_with_stdio( false );
	cin.tie( 0 );

	cin >> n;
	for ( int i = 0 ; i < n ; ++i ) {
		cin >> B[i] >> W[i];
	}

	iota( idx, idx + n, 0 );
	sort( idx, idx + n, [&] ( int id1, int id2 ) {
		return B[ id1 ] > B[ id2 ];
	} );

	int ans = n;

	long long current = 0ll;
	for ( int i = 0 ; i <= n ; ++i ) {

		if ( i > 0 and idx[i-1] != 0 ) {
			data2.insert( W[ idx[i-1] ] - B[ idx[i-1] ] + 1ll );
		}

		long long limit = B[ 0 ] - ( i < n ? B[ idx[i] ] : 0 );

		if ( limit < 0 ) continue;

		while ( ( not data1.empty() ) and ( not data2.empty() ) and ( *data1.rbegin() > *data2.begin() ) ) {
			auto val1 = *data1.rbegin(), val2 = *data2.begin();
			data1.erase( next( data1.rbegin() ).base() );
			data2.erase( data2.begin() );
			data1.insert( val2 );
			data2.insert( val1 );
			current += val2 - val1;
		}

		while ( ( not data2.empty() ) and ( current + *data2.begin() <= limit ) ) {
			current += *data2.begin();
			data1.insert( *data2.begin() );
			data2.erase( data2.begin() );
		}

		ans = min< int >( ans, data2.size() + 1 );
	}

	cout << ans << endl;

	return 0;
}