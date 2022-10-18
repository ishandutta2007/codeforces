#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	cout << accumulate(begin(a), end(a), 0) << '\n';
}