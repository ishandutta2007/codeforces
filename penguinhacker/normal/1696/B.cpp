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
		int ans=0;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		for (int i=0; i<n; ++i)
			if (a[i]&&(i==0||!a[i-1]))
				++ans;
		cout << min(ans, 2) << "\n";
	}
	return 0;
}