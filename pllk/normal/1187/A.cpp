#include <iostream>

using namespace std;

int main() {
	int z, n, s, t;
	cin >> z;
	while (z--) {
		cin >> n >> s >> t;
		cout << max(n-s,n-t)+1 << "\n";
	}
}