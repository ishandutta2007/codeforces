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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		sort(a.begin(), a.end());
		if (accumulate(a.begin(), a.end(), 0)==x) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int sum=0;
		for (int i=0; i<n; ++i) {
			sum+=a[i];
			if (sum==x) {
				swap(a[i], a[i+1]);
				break;
			}
		}
		for (int i : a)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}