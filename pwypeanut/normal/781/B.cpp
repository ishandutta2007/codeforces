#include <bits/stdc++.h>
using namespace std;

int N;
string ans[1005], A1[1005], B1[1005];
vector< pair< pair<char, char>, int > > v[705];
bool vis[26];
vector< pair<int, int> > adjlist[26];
bool used[26];

void dfs(int x) {
	if (vis[x] || adjlist[x].size() > 2) return;
	else vis[x] = 1;
	if (used[x]) {
		for (int i = 0; i < adjlist[x].size(); i++) {
			if (ans[adjlist[x][i].second].length() == 0) {
				int usin = adjlist[x][i].first;
				if (used[usin]) {
					printf("NO\n");
					exit(0);
				} else used[usin] = 1;
				ans[adjlist[x][i].second] = A1[adjlist[x][i].second].substr(0, 2) + (char)('A' + usin);
				dfs(adjlist[x][i].first);
			}
		}
	} else {
		for (int i = 0; i < adjlist[x].size(); i++) {
			if (ans[adjlist[x][i].second].length() == 0) {
				int usin = x;
				if (used[usin]) {
					printf("NO\n");
					exit(0);
				} else used[usin] = 1;
				ans[adjlist[x][i].second] = A1[adjlist[x][i].second].substr(0, 2) + (char)('A' + usin);
				dfs(adjlist[x][i].first);
			}
		}
	}
}

void dfs2(int x) {
	if (vis[x]) return;
	else vis[x] = 1;
		for (int i = 0; i < adjlist[x].size(); i++) {
			if (ans[adjlist[x][i].second].length() == 0) {
				//printf("%d\n", adjlist[x][i].second);
				int usin = adjlist[x][i].first;
				if (!used[x]) usin = x;
				if (used[usin]) {
					printf("NO\n");
					exit(0);
				} else used[usin] = 1;
				ans[adjlist[x][i].second] = A1[adjlist[x][i].second].substr(0, 2) + (char)('A' + usin);
				dfs2(adjlist[x][i].first);
			}
		}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string A, B;
		cin >> A >> B;
		A1[i] = A;
		B1[i] = B;
		int idx = (int)(A[0] - 'A') * 26 + (A[1] - 'A');
		v[idx].push_back(make_pair(make_pair(A[2], B[0]), i));
	}
	for (int i = 0; i < 26 * 26; i++) {
		if (v[i].size() == 0) continue;
		sort(v[i].begin(), v[i].end());
		
		memset(used, 0, sizeof(used));
		vector< pair<char, int> > v2[26];
		for (int j = 0; j < v[i].size(); j++) v2[v[i][j].first.first - 'A'].push_back(make_pair(v[i][j].first.second, v[i][j].second));
		for (int j = 0; j < 26; j++) {
			if (v2[j].size() > 1) {
				for (int k = 0; k < v2[j].size(); k++) {
					int x = v2[j][k].first - 'A';
					if (used[x]) {
						printf("NO\n");
						exit(0);
					} else used[x] = 1;
					ans[v2[j][k].second] += (i / 26) + 'A';
					ans[v2[j][k].second] += (i % 26) + 'A';
					ans[v2[j][k].second] += x + 'A';
				}
			}
		}
		for (int j = 0; j < 26; j++) adjlist[j].clear();
		//printf("hi\n");
		for (int j = 0; j < 26; j++) {
			//printf("hi %d\n", j);
			if (v2[j].size() == 1) {
				int x = j;
				int y = v2[j][0].first - 'A';
				int idx = v2[j][0].second;
				if (used[x] && used[y]) {
					printf("NO\n");
					exit(0);
				} else if (used[x]) {
					
					adjlist[y].push_back(make_pair(y, idx));
					adjlist[y].push_back(make_pair(y, idx));
				} else if (used[y]) {
					adjlist[x].push_back(make_pair(x, idx));
					adjlist[x].push_back(make_pair(x, idx));
				} else {
					adjlist[x].push_back(make_pair(y, idx));
					adjlist[y].push_back(make_pair(x, idx));
				}
			}
			//printf("wot\n");
		}
		//printf("hi end\n");
		memset(vis, 0, sizeof(vis));
		//printf("meow\n");
		for (int j = 0; j < 26; j++) {
			if (adjlist[j].size() == 1 && !vis[j]) {
				dfs(j);
			}
		}
		
		for (int j = 0; j < 26; j++) {
			if (!vis[j]) dfs2(j);
		}
		//printf("%d\n", i);
	}
	printf("YES\n");
	for (int i = 0; i < N; i++) printf("%s\n", ans[i].c_str());
}