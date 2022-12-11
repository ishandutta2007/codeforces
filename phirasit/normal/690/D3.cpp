#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e6 + 3ll;
const int H = 210;

int c, w, h;

typedef vector< vector< long long > > matrix;

long long dp[H];
matrix def;

matrix matrix_mul( matrix a, matrix b ) {
	matrix c( a.size(), vector<long long> ( b.size(), 0ll ) );
	for ( int i = 0 ;i < a.size() ; i++ ) {
		for ( int j = 0 ; j < b.size() ; j++ ) {
			c[i][j] = 0ll;
			for ( int k = 0 ; k < a.size() ; k++ ) {
				c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % mod;
			}
		}
	}
	return c;
}
matrix matrix_pw( int x ) {
	if ( x == 1 ) {
		return def;
	}

	matrix res = matrix_pw( x / 2 );
	res = matrix_mul ( res, res );
	if ( x % 2 ) {
		res = matrix_mul ( res, def );
	}

	return res;
}
int main() {

	ios::sync_with_stdio( false );

	cin >> c >> w >> h;

	dp[0] = 1ll;
	for ( int i = 1 ; i <= w ; i++ ) {
		dp[i] = ( dp[i-1] * (h+1) ) % mod;
	}
	if ( c <= w ) {
		cout << dp[c] << endl;
		return 0;
	}

	def.resize( w+1, vector<long long> (w+1, 0ll ) );
	for ( int i = 0 ; i <= w ; i++ ) {
		long long val = 1ll;
		for ( int j = 0 ; j <= w ; j++ ) {
			if ( i == 0 ) {
				def[i][j] = val;
				val = ( val * (h) ) % mod;
			} else {
				def[i][j] = ( j == i-1 );
			}
		}
	}

	matrix res = matrix_pw( c-w );

	long long ans = 0ll;
	long long val = 1ll;
	for ( int i = 0 ; i <= w ; i++ ) {
		ans = ( ans + dp[w-i] * res[0][i] ) % mod;
		val = ( val * (h+1) ) % mod;

	}

	cout << ans << endl;

	return 0;
}