#include <iostream>

const long long mod = 1e9 + 7ll;
const int N = 30;

long long inv[ N ];

long long f[ N ], s;
int n;

long long C( long long x, long long r ) {
    if ( r < 0 ) return 0;
    long long ans = 1ll;
    for ( auto i = r + 1 ; i <= x ; ++i ) {
        ans = ( ans * ( i % mod ) ) % mod;
    }
    for ( auto i = 1ll ; i <= x-r ; ++i ) {
        ans = ( ans * inv[i] ) % mod;
    }
    return ans;
}
long long solve( int idx, long long coef, long long degree ) {
    if ( idx >= n ) return coef * C( s - degree + n - 1, s - degree );
    return ( solve( idx+1, coef, degree ) + solve( idx+1, coef * -1, degree + f[ idx ] + 1 ) ) % mod;
}

int main( void ) {

    std::cin.sync_with_stdio( false );
    std::cin.tie( 0 );

    inv[ 1 ] = 1ll;
    for ( int i = 2ll ; i < N ; ++i ) {
        inv[ i ] = ( ( mod - mod / i ) * inv[ mod % i ] ) % mod;
    }

    std::cin >> n >> s;
    for ( int i = 0 ; i < n ; ++i ) {
        std::cin >> f[i];
    }

    long long ans = solve( 0, 1ll, 0ll );
    ans = ( ans % mod + mod ) % mod;
    std::cout << ans << std::endl;

    return 0;
}