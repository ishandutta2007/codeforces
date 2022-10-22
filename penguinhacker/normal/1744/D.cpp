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
		int cnt=0, cur=0;
		for (int i=1; i<=n; ++i) {
			int x;
			cin >> x;
			cur+=__builtin_ctz(x);
			a[i-1]=__builtin_ctz(i);
		}
		if (cur>=n) {
			cout << "0\n";
			continue;
		}
		sort(a.rbegin(), a.rend());
		int ans=0;
		for (int i : a) {
			cur+=i;
			++ans;
			if (cur>=n)
				break;
		}
		cout << (cur>=n?ans:-1) << "\n";
	}
	return 0;
}