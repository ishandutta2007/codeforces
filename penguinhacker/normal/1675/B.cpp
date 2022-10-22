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
		int ans=0;
		bool ok=1;
		for (int i=n-2; ~i; --i) {
			if (a[i+1]==0) {
				ok=0;
				break;
			}
			while(a[i]>=a[i+1])
				++ans, a[i]/=2;
		}
		cout << (ok?ans:-1) << "\n";
	}
	return 0;
}