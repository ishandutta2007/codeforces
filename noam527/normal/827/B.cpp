#include <iostream>
using namespace std;
int main() {
	int n, k;
	ios::sync_with_stdio(0), cin >> n >> k, cout << ((n - 2) / k * 2 + ((n - 2) % k ? 2 : 1)) << endl;
	for (int i = 0; i < n - 1; i++) cout << i + 2 << " " << (i + 1 > k ? i + 2 - k : 1) << endl;
}