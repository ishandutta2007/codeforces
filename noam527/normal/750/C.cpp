#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isinfi = true, isimpo = false;
int l = -2e9, r = 2e9, c, d, n;

pair<int, int> Merge(int left, int right, int ml, int mr) {
	if (ml > right || mr < left) {
		isimpo = true;
		return{ -1, -1 };
	}
	return{ max(left, ml), min(right, mr) };
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> c >> d;
		pair<int, int> temp;
		if (d == 1) temp = Merge(l, r, 1900, 2e9);
		else temp = Merge(l, r, -2e9, 1899), isinfi = false;
		l = temp.first + c, r = temp.second + c;
	}
	if (isimpo) cout << "Impossible" << endl;
	else if (isinfi) cout << "Infinity" << endl;
	else cout << r << endl;
	return 0;
}