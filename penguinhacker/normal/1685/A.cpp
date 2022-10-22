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
		if (n%2) {
			cout << "NO\n";
			continue;
		}
		sort(a.begin(), a.end());
		vector<int> ans(n);
		for (int i=0; i<n; ++i)
			if (i%2==0)
				ans[i]=a[i/2];
		vector<ar<int, 2>> pos;
		for (int i=0; i<n/2; ++i)
			pos.push_back({max(ans[2*i], ans[(2*i+2)%n]), 2*i+1});
		sort(pos.begin(), pos.end());
		bool ok=1;
		for (int i=0; i<n/2; ++i) {
			//cout << 
			if (a[i+n/2]<=pos[i][0]) {
				ok=0;
				break;
			}
			//cout << a[i+n/2] << endl;
			ans[pos[i][1]]=a[i+n/2];
		}
		if (!ok) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}