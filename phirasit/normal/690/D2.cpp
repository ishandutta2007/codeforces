#include <iostream>

using namespace std;

const long long mod = 1e6 + 3ll;
const int N = 1000010;

long long fac[N];
int n, c;

long long pw ( long long a, long long b ) {
	if ( b == 0ll ) return 1ll;
	long long r = pw ( a, b/2ll );
	r = ( r * r ) % mod;
	if ( b % 2ll ) r = ( a * r ) % mod;
	return r;
}
long long inv( long long x ) {
	return pw( x, mod-2ll );
}
int main() {

	ios::sync_with_stdio( false );

	cin >> n >> c;

	fac[0] = 1ll;
	for ( int i = 1 ; i <= n + c ; i++ ) {
		fac[i] = ( fac[i-1] * i ) % mod;
	}

	long long ans = 0ll;
	for ( int i = 1 ; i <= n ; i++ ) {
		long long val = 1ll;
		val = ( val * fac[i+c-1] );
		val = ( val * inv( fac[i] ) );
		val = ( val * inv( fac[c-1] ) );
		ans = ( ans + val ) % mod;
	}

	cout << ans << endl;

	return 0;
}