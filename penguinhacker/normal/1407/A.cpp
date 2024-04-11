#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
void test_case() {
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	int x=count(a.begin(), a.end(), 0);
	if (x>=n/2) {
		cout << x << "\n";
		for (int i=0; i<x; ++i) cout << 0 << " ";
		cout << "\n";
		return;
	}
	x=n-x;
	if (x%2==1) --x;
	cout << x << "\n";
	for (int i=0; i<x; ++i) cout << 1 << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		test_case();
	}
	return 0;
}