#include <bits/stdc++.h>

#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int a[MAX], b[MAX];
int n, m;

int main() {
    cin>>n>>m;
	fori(i, 0, m) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fori(i, 1, n + 1) {
	    cin>>a[i];
	}

	queue<int> q;
	fori(i, 1, n + 1) {
		if(a[i] == b[i]) {
			q.push(i);
		}
	}

	vector<int> ans;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		b[cur]++;
		for(auto &each : adj[cur]) {
			b[each]++;
			if(b[each] == a[each]) {
				q.push(each);
			}
		}
	}

	cout<<(int) ans.size()<<endl;
	for(auto &each : ans) {
	    cout<<each<<' ';
	}
	cout<<endl;
}