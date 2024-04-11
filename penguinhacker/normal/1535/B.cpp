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
		sort(a.begin(), a.end(), [](int x, int y) {return x%2<y%2;});
		int ans=0;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				ans+=__gcd(a[i], 2*a[j])>1;
		cout << ans << "\n";
	}
	return 0;
}