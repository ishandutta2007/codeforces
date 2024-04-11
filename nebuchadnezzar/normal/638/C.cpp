#include <cstdio>
#include <vector>
#include <algorithm>

int const N = 200200;

std::vector<std::pair<int, int>> g[N];
int q[N];
int prevc[N];
bool used[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		g[a].emplace_back(b, i);
		g[b].emplace_back(a, i);
	}
	int colors = 0;
	for (int i = 0; i < n; ++i) {
		colors = std::max<int>(colors, g[i].size());
	}
	std::vector<std::vector<int>> edges(colors);
	std::fill(prevc, prevc + n, -1);
	int tail = 0;
	q[tail++] = 0;
	used[0] = true;
	for (int head = 0; head < tail; ++head) {
		int v = q[head];
		int color = 0;
		for (auto& edge : g[v]) {
			int to = edge.first;
			int ind = edge.second;
			if (!used[to]) {
				do {
					color = (color + 1) % colors;
				} while (color == prevc[v]);
				used[to] = true;
				q[tail++] = to;
				prevc[to] = color;
				edges[color].push_back(ind);
			}
		}
	}
	printf("%d\n", colors);
	for (int i = 0; i < colors; ++i) {
		printf("%d", edges[i].size());
		for (int ind : edges[i]) {
			printf(" %d", ind + 1);
		}
		puts("");
	}
}