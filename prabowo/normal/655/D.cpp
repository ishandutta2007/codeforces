#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>

const int N = 100000;

int n, m;
std::pair <int, int> battle[N];

bool check (int x) {
	std::queue <int> q;
	int inEdge[n];
	std::vector <int> edge[n];
	memset (inEdge, 0, sizeof inEdge);
	
	for (int i=0; i<x; i++) {
		edge[battle[i].first].push_back(battle[i].second);
		inEdge[battle[i].second]++;
	}
	
	for (int i=0; i<n; i++) if (inEdge[i]);
	else q.push(i);
	
	int cnt = 0;
	while (q.size()) {
		if (q.size() > 1) return 0;
		int now = q.front();
		q.pop();
		
		cnt++;
		
		for (int i=0; i<edge[now].size(); i++) {
			inEdge[edge[now][i]]--;
			if (inEdge[edge[now][i]] == 0)
				q.push(edge[now][i]);
		}
	}
	
	return cnt == n;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i=0; i<m; i++)
		scanf ("%d %d", &battle[i].first, &battle[i].second),
		battle[i].first--, battle[i].second--;
		
	int l = 1;
	int r = m;
	int ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else l = mid + 1;
	}
	
	printf ("%d\n", ans);
	return 0;
}