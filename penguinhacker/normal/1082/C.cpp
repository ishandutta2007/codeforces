#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, ans=0;
map<int, vector<int>> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, s, r; i<n; ++i) {
		cin >> s >> r;
		mp[s].push_back(r);
	}
	for (auto &x : mp) {
		vector<int> &v=x.second;
		sort(v.rbegin(), v.rend());
		for (int i=1; i<v.size(); ++i)
			v[i]+=v[i-1];
	}
	for (int i=0; i<n; ++i) {
		int curr=0;
		for (auto it=mp.begin(); it!=mp.end();) {
			vector<int> v=it->second;
			if (v.size()<i+1||v[i]<=0)
				it=mp.erase(it);
			else {
				curr+=v[i];
				++it;
			}
		}
		ans=max(ans, curr);
		if (curr=0)
			break;
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