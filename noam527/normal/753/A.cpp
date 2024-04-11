#include <iostream>
#include <algorithm>
#define last(X) (X)[(X).size() - 1]
typedef long long ll;
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin >> n, k = floor((-1 + sqrt(1.0 + 8 * n)) / 2.0);
	cout << k << endl;
	for (int i = 0; i < k - 1; i++) cout << i + 1 << " ", n -= i + 1;
	cout << n << endl;
	return 0;
}