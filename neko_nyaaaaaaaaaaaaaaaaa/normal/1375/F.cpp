#include <bits/stdc++.h>
using namespace std;

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	vector<long long> a(3);
	cin >> a[0] >> a[1] >> a[2];
	
	cout << "First" << endl;

	long long f = 1e10;
	cout << f << endl;

	int x; cin >> x;
	if (x == 0) exit(0);
	a[x-1] += f;

	long long mx = *max_element(a.begin(), a.end());
	long long g = 0;
	for (long long i: a) {
		g += mx - i;
	}
	cout << g << endl;

	cin >> x;
	if (x == 0) exit(0);
	a[x-1] += g;

	sort(a.begin(), a.end());
	cout << a[1] - a[0] << endl;

	return 0;
}