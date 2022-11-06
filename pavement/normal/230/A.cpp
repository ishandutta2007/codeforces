#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int s, n;
	cin >> s >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	for (auto i : a) {
		if (s <= i.first) {
			cout << "NO";
			return 0;
		}
		s += i.second;
	}
	cout << "YES";
}