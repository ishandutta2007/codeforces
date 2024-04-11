#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cnt=0;
vector<int> ans;
set<int> active;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	bool pos=1;
	for (int i=0, a; i<n; ++i) {
		cin >> a, ++cnt;
		if (a>0) {
			if (mp[a]) {
				pos=0;
				break;
			}
			++mp[a];
			active.insert(a);
		}
		else {
			a=-a;
			if (mp[a]!=1) {
				pos=0;
				break;
			}
			++mp[a];
			active.erase(a);
		}
		if (active.empty()) {
			mp.clear();
			ans.push_back(cnt);
			cnt=0;
		}
	}
	if (!active.empty()||!mp.empty())
		pos=0;
	if (!pos) {
		cout << -1;
		return 0;
	}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/