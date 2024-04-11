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
			cin >> i;
		if (a[0]!=n&&a.back()!=n) {
			cout << "-1\n";
			continue;
		}
		reverse(a.begin(), a.end());
		for (int i : a)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}