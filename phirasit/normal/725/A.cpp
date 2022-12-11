#include <iostream>

using namespace std;

int main( void ) {

	int n;
	std::string data;

	std::cin >> n >> data;

	int left = 0, right = n-1;
	while ( left < data.size() and data[ left ] == '<' ) {
		++left;
	}
	while ( right >= 0 and data[ right ] == '>' ) {
		--right;
	}
	cout << left + ( n-1 - right ) << endl;
	return 0;
}