#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, cnt[mxN];
bool vis[mxN];
unordered_set<int> foods[mxN];
ar<int, 2> person[2*mxN];
vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> cnt[i];
	}
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		foods[a].insert(i);
		foods[b].insert(i);
		person[i]={a, b};
	}
	queue<int> q;
	for (int i=0; i<n; ++i) {
		if (cnt[i]>=foods[i].size()) {
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for (const int &ind : foods[u]) {
			ans.push_back(ind);
			int other=u==person[ind][0]?person[ind][1]:person[ind][0];
			//foods[u].erase(foods[u].begin());
			foods[other].erase(ind);
			if (!vis[other]&&cnt[other]>=foods[other].size()) {
				q.push(other);
				vis[other]=1;
			}
		}
	}
	assert(ans.size()<=m);
	if (ans.size()<m) {
		cout << "DEAD";
	}
	else {
		cout << "ALIVE\n";
		reverse(ans.begin(), ans.end());
		for (int i: ans) {
			cout << i+1 << " ";
		}
	}
	return 0;
}