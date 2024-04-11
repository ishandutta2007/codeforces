#include <bits/stdc++.h>
using namespace std;
 
int n, m;
map<pair<int, int>, bool> edge;
set<int> todo;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		edge[make_pair(u, v)]=1;
		edge[make_pair(v, u)]=1;
	}
	for (int i=0; i<n; ++i) {
		todo.insert(i);
	}
	
	int ans=-1;
	while(!todo.empty()) {
		int i = *todo.begin();
		todo.erase(todo.begin());
		ans++;
 
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int x=q.front();
			q.pop();
 
			auto it=todo.begin();
			while (it!=todo.end()) {
				bool found=0;
				if (!edge[make_pair(x, *it)])
					found=1;
				if (found) {
					q.push(*it);
					it = todo.erase(it);
				}
				else {
					it++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}