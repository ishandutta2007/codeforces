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
		vector<int> a(2*n);
		for (int& i : a)
			cin >> i;
		sort(a.begin(), a.end());
		for (int i=0; i<n; ++i)
			cout << a[i] << " " << a[2*n-i-1] << " ";
		cout << "\n";
	}
	return 0;
}