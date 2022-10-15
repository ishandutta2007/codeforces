#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;
	cout << 3 << " " << 3 << "\n";
	cout << ((1<<17)|k) << " " << (1<<17) << " " << 0 << "\n";
	cout << ((1<<17)-1) << " " << ((1<<18)-1) << " " << k << "\n";
	cout << 0 << " " << k << " " << k << "\n"; 
}