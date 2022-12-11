#include <iostream>

using namespace std;

int main( void ) {

	int n;
	cin >> n;

	for ( int i = 0 ; i < n ; ++i ) {
		cout << "I ";
		cout << ( i % 2 ? "love " : "hate " );
		cout << ( i + 1 < n ? "that " : "it" );
	}

	cout << endl;
	return 0;
}