#include <algorithm>
#include <iostream>
#include <iomanip>
#include <functional>

const int N = 110;

double arr[ N ];
int n;

int main( void ) {

    std::cin >> n;
    for ( int i = 0 ; i < n ; ++i ) {
        std::cin >> arr[ i ];
        if ( arr[i] == 1.0 ) {
            std::cout << 1.0 << std::endl;
            return 0;
        }
    }

    sort( arr, arr + n, std::greater< double >() );

    double ans = 0.0;
    for ( int i = 0 ; i < n ; ++i ) {
        double total = 1.0, sum = 0.0;
        for ( int j = 0 ; j <= i ; ++j ) {
            total *= 1.0 - arr[j];
            sum += arr[j] / ( 1.0 - arr[j] );
        }
        ans = std::max( ans, total * sum );
    }

    std::cout << std::setprecision( 10 ) << std::fixed;
    std::cout << ans << std::endl;

    return 0;
}