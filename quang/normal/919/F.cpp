#include <bits/stdc++.h>

using namespace std;

const int N = 500;

vector<vector<int> > state;
map<vector<int>, int> id;
int dp[N][N], deg[N][N];
vector<pair<int, int> > adj[N][N];

void init(vector<int> &u, int pos, int tot) {
	if (pos == 5) {
		if (tot == 0) {
			id[u] = state.size();
			state.push_back(u);
		}
		return;
	}
	for (int i = 0; i <= tot; i++) {
		u[pos] = i;
		init(u, pos + 1, tot - i);
	}
}

vector<int> getVec() {
	vector<int> res(5, 0);
	for (int i = 1; i <= 8; i++) {
		int u;
		scanf("%d", &u);
		res[u]++;
	}
	return res;
}

int main() {	
	memset(dp, -1, sizeof dp);
	vector<int> foo(5);
	init(foo,0, 8);
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			for (int k = 1; k < 5; k++) {
				if (state[i][k] == 0) {
					continue;
				}
				for (int kk = 1; kk < 5; kk++) {
					if (state[j][kk] == 0) {
						continue;
					}
					vector<int> now = state[i];
					now[k]--;
					now[(k + kk) % 5]++;
					int idNow = id[now];
					adj[j][idNow].emplace_back(i, j);
					deg[i][j]++;
				}
			}
		}
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			if (!deg[i][j]) {
				q.emplace(i, j);
				dp[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int u, v;
		tie(u, v) = q.front();
		q.pop();
		if (dp[u][v] < 0) {
			dp[u][v] = 0;
		}
		for (auto w : adj[u][v]) {
			--deg[w.first][w.second];
			if (!dp[u][v] && deg[w.first][w.second] >= 0) {
				dp[w.first][w.second] = 1;
				deg[w.first][w.second] = 0;
				q.push(w);
			} else if (deg[w.first][w.second] == 0) {
				q.push(w);
			}
		} 
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int f;
		scanf("%d", &f);
		vector<int> x = getVec();
		vector<int> y = getVec();
		int u = id[x];
		int v = id[y];
		if (f) {
			swap(u, v);
		}
		if (dp[u][v] == -1) {
			puts("Deal");
		} else if (dp[u][v] ^ f) {
			puts("Alice");
		} else {
			puts("Bob");
		}
	}
	return 0;
}