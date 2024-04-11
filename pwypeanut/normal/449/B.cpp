#include <bits/stdc++.h>
using namespace std;

bool vis[300005];
int N, R, E;
vector< pair<int, int> > adjlist[300005];
vector<int> expressways[300005];
priority_queue< pair< pair<long long, int>, int>, vector< pair< pair<long long, int>, int> >, greater< pair< pair<long long, int>, int> > > PQ;

int main() {
	scanf("%d%d%d", &N, &R, &E);
	for (int i = 0; i < R; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		adjlist[a].push_back(make_pair(b, c));
		adjlist[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		expressways[a].push_back(b);
	}
	int ans = E;
	PQ.push(make_pair(make_pair(0, 0), 0));
	while (!PQ.empty()) {
		long long d = PQ.top().first.first;
		int fr_expressway = PQ.top().first.second;
		int node = PQ.top().second;
		PQ.pop();
		
		if (vis[node]) continue;
		else vis[node] = 1;
		if (fr_expressway) ans--;
		for (int i = 0; i < adjlist[node].size(); i++) {
			int newnode = adjlist[node][i].first;
			long long newd = d + adjlist[node][i].second;
			if (vis[newnode]) continue;
			PQ.push(make_pair(make_pair(newd, 0), newnode));
		}
		if (node == 0) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < expressways[i].size(); j++) {
					int newnode = i;
					long long newd = d + expressways[i][j];
					if (vis[newnode]) continue;
					PQ.push(make_pair(make_pair(newd, 1), newnode));
				}
			}
		}
	}
	printf("%d\n", ans);
}