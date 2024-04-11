#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int k = 3;
	for (; k < a.size() && a[k] == a[2]; k++);
	if (a[0] == a[2]) {
		cout << (long long)k * (k - 1) * (k - 2) / 6 << endl;
		return 0;
	}
	if (a[0] == a[1]) {
		cout << k - 2 << endl;
		return 0;
	}
	if (a[1] == a[2]) {
		cout << (long long)(k - 1) * (k - 2) / 2 << endl;
		return 0;
	}
	cout << k - 2 << endl;
	return 0;
}