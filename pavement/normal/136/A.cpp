#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p;
	cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		cin >> p;
		a[i] = make_pair(p, i + 1); 
	}
	sort(a, a + n);
	for (auto i : a) cout << i.second << " ";
}