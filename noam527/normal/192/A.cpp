#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	for (int k = 1; k * (k + 1) / 2 <= 1e9; k++) a.push_back(k * (k + 1) / 2);
	int n, p1 = 0, p2 = a.size() - 1;
	cin >> n;
	while (p1 <= p2)
		if (a[p1] + a[p2] == n) {
			cout << "YES" << endl;
			return 0;
		}
		else if (a[p1] + a[p2] < n)
			p1++;
		else
			p2--;
	cout << "NO" << endl;
	return 0;
}