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
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		string ans(n, '0');
		for (int i=n-1, cur=0; ~i; --i) {
			if (a[i]<=cur)
				ans[i]='1';
			else if (cur<q) {
				ans[i]='1';
				++cur;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}