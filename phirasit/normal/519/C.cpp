#include <iostream>

using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	int a = 0, b = n + m;
	while(a < b) {
		int mid = (a + b) / 2 + 1;
		if(mid > n || mid > m) {
			b = mid - 1;
			continue;
		}
		int x = n - mid, y = m - mid;
		if(x + y >= mid) {
			a = mid;
		}else {
			b = mid - 1;
		}
	}
	cout << a << endl;
	return 0;
}