#include <bits/stdc++.h>
using namespace std;

int n;

int get_val(int x) {
	if (x == 0 || x == n + 1) return 0x3f3f3f3f;
	cout << "? " << x << endl;
	int tmp; cin >> tmp;
	return tmp;
}

int Query(int x) {
	int v1 = get_val(x), v2 = get_val(x + 1);
	return v1 < v2;
}

int main () {
	cin >> n;
	int l = 0, r = n;
	while (l + 1 < r) {
		int mid = l + r >> 1;
		if (Query(mid)) r = mid;
		else l = mid;
	}
	cout << "! " << r << endl;
	return 0;
}