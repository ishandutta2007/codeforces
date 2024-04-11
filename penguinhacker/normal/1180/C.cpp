#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q;
ar<int, 2> p[100000];
deque<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	a.resize(n);
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i) {
		p[i] = {a[0], a[1]};
		int x = max(a[0], a[1]), y = min(a[0], a[1]);
		a.pop_front(), a.pop_front();
		a.push_front(x), a.push_back(y);
	}
	while(q--) {
		ll m;
		cin >> m, --m;
		if (m < n) {
			cout << p[m][0] << " " << p[m][1] << "\n";
		} else {
			m = (m - n) % (n - 1) + 1;
			cout << a[0] << " " << a[m] << "\n";
		}
	}
	return 0;
}