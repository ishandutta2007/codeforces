#include <iostream>
using namespace std;

int main()
{
	int n, k, a[100], b[100];
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) cin >> b[i];
	if (k > 1) {
		cout << "YES" << endl;
		return 0;
	}
	int j = 0;
	for (; a[j] != 0; j++);
	a[j] = b[0];
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1]) {
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
}