#include <iostream>
using namespace std;
int a[1001];
int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> n;
		for (int j = 1; j <= n; ++j) a[j] = 0;
		for (int j = 0; j < n; ++j) {
			int tmp;
			cin >> tmp;
			++a[tmp];
		}
		int ct = 0;
		for (int j = n; j > 0; --j) {
			ct += a[j];
			if (ct >= j) {
				cout << j << "\n";
				break;
			}
		}
	}
	return 0;
}