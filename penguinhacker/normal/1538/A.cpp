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
		int i=min_element(a.begin(), a.end())-a.begin();
		int j=max_element(a.begin(), a.end())-a.begin();
		if (i>j)
			swap(i, j);
		int ans=min(j+1, n-i);
		ans=min(ans, i+1+n-j);
		cout << ans << "\n";
	}
	return 0;
}