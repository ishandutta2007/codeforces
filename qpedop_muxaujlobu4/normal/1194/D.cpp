#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t, n, k;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> k;
		if (k % 3 == 1||k%3==2) {
			if (n % 3 == 0)
				cout << "Bob\n";
			else cout << "Alice\n";
		}
		if (k % 3 == 0) {
			n %= (k + 1);
			if (n % 3 == 0 && k != n)
				cout << "Bob\n";
			else cout << "Alice\n";
		}
	}
	return 0;
}