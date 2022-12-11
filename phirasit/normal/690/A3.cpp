#include <iostream>

int main() {

	std::cin.sync_with_stdio( false );
	std::cin.tie( 0 );

	int test;
	std::cin >> test;
	
	while ( test-- ) {
		int n, r;
		std::cin >> n >> r;

		int sum = r;
		for ( int i = 0 ; i < n-1 ; ++i ) {
			int val;
			std::cin >> val;
			sum -= val;
		}

		sum = ( sum % n + n ) % n;

		std::cout << ( sum + 1 ) << "\n";
	}

	return 0;
}