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
		int cnt=0;
		for (int& i : a)
			cin >> i, cnt+=i%2;
		int ans=0;
		if (!cnt) {
			int mn=69;
			for (int i : a)
				mn=min(mn, __builtin_ctz(i));
			ans+=mn;
			++cnt;
		}
		ans+=n-cnt;
		cout << ans << "\n";
	}
	return 0;
}