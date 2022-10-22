#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		iota(a.begin(), a.end(), 1);
		cout << n << "\n";
		auto pr=[&]() {
			for (int j : a)
				cout << j << " ";
			cout << "\n";
		};
		pr();
		swap(a[0], a[1]);
		pr();
		for (int i=2; i<n; ++i) {
			swap(a[i], a[i-1]);
			pr();
		}
	}
	return 0;
}