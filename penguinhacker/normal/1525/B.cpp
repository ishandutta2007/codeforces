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
		for (int& i : a)
			cin >> i, --i;
		bool ok=1;
		for (int i=0; i<n; ++i)
			ok&=i==a[i];
		if (ok) {
			cout << "0\n";
		} else if (a[0]==0||a[n-1]==n-1) {
			cout << "1\n";
		} else if (a[0]==n-1&&a[n-1]==0) {
			cout << "3\n";
		} else {
			cout << "2\n";
		}
	}
	return 0;
}