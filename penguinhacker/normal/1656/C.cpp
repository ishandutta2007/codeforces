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
		sort(a.begin(), a.end());
		bool one=find(a.begin(), a.end(), 1)!=a.end();
		if (!one) {
			cout << "YES\n";
			continue;
		}
		if (a[0]==0) {
			cout << "NO\n";
			continue;
		}
		bool ok=1;
		for (int i=0; i+1<n; ++i)
			ok&=a[i]+1!=a[i+1];
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}