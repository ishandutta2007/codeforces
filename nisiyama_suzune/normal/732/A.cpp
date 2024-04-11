#include <iostream>

using namespace std;

int K, R;

int main () {
	cin >> K >> R;
	for (int i = 1; i <= 9; i++)
		if ((K * i >= R && (K * i - R) % 10 == 0) || (K * i % 10 == 0)) {
			cout << i << endl;
			return 0;
		}
	cout << 10 << endl;
}