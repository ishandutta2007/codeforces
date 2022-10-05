#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define loop(i, a, n) for (int (i) = (a); (i) < (n); i++)
using namespace std;

int main() {
	int n, mx = 1, c = 1;
	cin >> n;
	vector<int> a(n);
	loop(i, 0, a.size()) cin >> a[i];
	loop(i, 1, a.size()) {
		if (a[i] >= a[i - 1]) c++;
		else mx = max(mx, c), c = 1;
	}
	cout << max(mx, c) << endl;
}