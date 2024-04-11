#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	int n, m, mn = 1e9;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	sort(begin(a), end(a));
	for (int i = 0; i + n - 1 < m; i++)
		mn = min(mn, a[i + n - 1] - a[i]);
	cout << mn << endl;
}