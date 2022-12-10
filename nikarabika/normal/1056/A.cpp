//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i <= 100; i++)
		s.insert(i);
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		set<int> t;
		while (c--) {
			int x;
			cin >> x;
			if (s.find(x) != s.end())
				t.insert(x);
		}
		s = t;
	}
	for (auto x : s)
		cout << x << ' ';
	cout << endl;
	return 0;
}