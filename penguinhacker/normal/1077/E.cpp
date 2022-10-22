#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
map<int, int> mp;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, a; i<n; ++i)
		cin >> a, ++mp[a];
	for (auto x : mp)
		v.push_back(x.second);
	sort(v.rbegin(), v.rend());
	v.resize(min((int)v.size(), 18));
	int ans=0;
	for (int i=1; i<=v.size(); ++i) {
		for (int j=1; ; ++j) {
			bool b=1;
			for (int k=0; k<i; ++k)
				if ((j<<(i-k-1))>v[k]) {
					b=0;
					break;
				}
			if (!b) break;
			ans=max(ans, j*((1<<i)-1));
		}
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/