#include <iostream>

using namespace std;

int n, k, a[500];
int b[500] = {0};

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];	
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		b[i] = a[i];
		if (b[i] + b[i - 1] < k)
			b[i] = k - b[i - 1];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += b[i] - a[i];
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
}