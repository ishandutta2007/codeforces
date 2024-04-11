#include <bits/stdc++.h>
using namespace std;

int w[1005][1005];
vector< pair< pair<int, int>, int> > ans;
vector<int> v[1005];
int reord[1005], end1[1005],cur, backord[1005];

void dfs2(int x, int p) {
	reord[x] = cur;
	backord[cur] = x;
	cur++;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs2(v[x][i], x);
	end1[x] = cur;
}

bool found = 0;

void draw_path(int s, int e, int p, int d) {
	if (found) return;
	if (s == e) {
		if (p != -1) {
			w[s][p] -= d;
			w[p][s] -= d;
		}
		found = 1;
		return;
	}
	for (int i = 0; i < v[s].size(); i++) {
		if (v[s][i] == p) continue;
		draw_path(v[s][i], e, s, d);
		if (found) {
			if (p != -1) {
				w[s][p] -= d;
				w[p][s] -= d;
			}
			return;
		}
	}
}

int rt;

int rchild(int x) {
	return backord[end1[x] - 1];
}

void dfs(int x, int p) {
	int children = (v[x].size() - (p != -1));
	vector<int> child;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) child.push_back(v[x][i]);
	if (children == 1) {
		if (w[child[0]][x] != 0) {
			assert(p == -1);
			ans.push_back(make_pair(make_pair(x, rchild(x)), w[child[0]][x]));
			found=0;
			draw_path(rchild(x), x, -1, w[child[0]][x]);
		}
	} else {
		int times = 0;
		if (child.size() % 2 == 0) times = child.size();
		else times = child.size() - 3;
		for (int i = 0; i < times; i += 2) {
			int diff = (w[child[i]][x] - w[child[i+1]][x]) / 2;
			ans.push_back(make_pair(make_pair(rt, rchild(child[i])), diff));
			ans.push_back(make_pair(make_pair(rt, rchild(child[i+1])), -diff));
			found=0;
			draw_path(rt, rchild(child[i]), -1, diff);
			found=0;
			draw_path(rt, rchild(child[i+1]), -1, -diff);
			//printf("%d %d %d\n", rt, rchild(child[i]), diff);
			//printf("%d %d %d\n", rt, rchild(child[i+1]), -diff);
			//printf("%d %d\n", w[child[i]][x], w[child[i+1]][x]);
			assert(w[child[i]][x] == w[child[i+1]][x]);
			
			ans.push_back(make_pair(make_pair(rchild(child[i]), rchild(child[i+1])), w[child[i]][x]));
			found=0;
			draw_path(rchild(child[i]), rchild(child[i+1]), -1, w[child[i]][x]);
		}
		if (child.size() % 2 == 1) {
			int child1 = child[child.size() - 1], child2 = child[child.size() - 2], child3 = child[child.size() - 3];
			int sum = (w[child1][x] + w[child2][x] + w[child3][x]) / 2;
			int a = sum - w[child3][x], b = sum - w[child1][x], c = sum - w[child2][x];
			ans.push_back(make_pair(make_pair(rchild(child1), rchild(child2)), a));
			found=0;
			draw_path(rchild(child1), rchild(child2), -1, a);
			ans.push_back(make_pair(make_pair(rchild(child2), rchild(child3)), b));
			found=0;
			draw_path(rchild(child2), rchild(child3), -1, b);
			ans.push_back(make_pair(make_pair(rchild(child3), rchild(child1)), c));
			found=0;
			draw_path(rchild(child3), rchild(child1), -1, c);
		}
	}
	for (int i = 0; i < child.size(); i++) dfs(child[i], x);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a][b] = c;
		w[b][a] = c;
	}
	bool whack = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].size() == 2) {
			if (w[v[i][0]][i] != w[v[i][1]][i]) whack = 1;
		}
	}
	if (whack) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if (N == 2) {
		printf("1\n1 2 %d\n", w[0][1]);
		return 0;
	}
	for (int i = 0; i < N; i++) if (v[i].size() == 1) rt = i;
	dfs2(rt, -1);
	dfs(rt, -1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) assert(w[i][j] == 0);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
}