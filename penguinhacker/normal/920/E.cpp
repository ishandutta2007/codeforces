#include <bits/stdc++.h>
using namespace std;

int n, m;
map<pair<int, int>, bool> noEdge;
set<int> todo;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v;
		noEdge[make_pair(u, v)]=1;
		noEdge[make_pair(v, u)]=1;
	}
	for (int i=1; i<=n; ++i) {
		todo.insert(i);
	}
	
	vector<int> ans;
	while(!todo.empty()) {
		int i = *todo.begin();
		todo.erase(todo.begin());
		int sizeComp=0;

		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int x=q.front();
			q.pop();
			sizeComp++;

			auto it=todo.begin();
			while (it!=todo.end()) {
				bool found=0;
				if (!noEdge[make_pair(x, *it)]) {
					found=1;
				}
				if (found) {
					q.push(*it);
					it = todo.erase(it);
				}
				else {
					it++;
				}
			}
		}
		ans.push_back(sizeComp);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i:ans)
		cout << i << ' ';
	return 0;
}