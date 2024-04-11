#include <iostream>

using namespace std;

int main() {
	long long x;
	cin >> x;
	cout << ( ( x - 1 ) >> 1 ) + 1ll << endl;
	return 0;	
}