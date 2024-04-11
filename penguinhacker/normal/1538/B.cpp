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
		int s=accumulate(a.begin(), a.end(), 0);
		if (s%n) {
			cout << "-1\n";
			continue;
		}
		int ans=0;
		s/=n;
		for (int i : a)
			ans+=i>s;
		cout << ans << "\n";
	}
	return 0;
}