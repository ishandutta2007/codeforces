/*
_NUUUUUUU_
*/

#include<iostream>
#include<algorithm>
#include<vector>;
#include<map>
#include<set>

using namespace std;
typedef long long ll;

ll n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	cin >> n >> m;
	vector<bool> used(n + 1);
	vector<vector<int>> g(n+1,vector<int>(0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	set<int> s;
	s.insert(1);
	vector<int> ans;
	while (s.size() != 0) {
		int now = *s.begin();
		s.erase(s.begin());
		ans.push_back(now);
		used[now] = 1;
		for (auto to : g[now]) {
			if (!used[to]) {
				s.insert(to);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}