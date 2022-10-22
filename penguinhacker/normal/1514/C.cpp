#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll p=1;
	vector<int> ans;
	for (int i=1; i<n; ++i)
		if (__gcd(i, n)==1)
			ans.push_back(i), p=p*i%n;
	if (p>1) {
		auto it=find(ans.begin(), ans.end(), p);
		assert(it!=ans.end());
		ans.erase(it);
	}
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
	return 0;
}