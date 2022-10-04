#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef pair<pair<int, int >, int> piii;

piii edges[100000];
int u[100000];
int v[100000];
int pos = 1;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		edges[i] = mp(mp(x, -y),i);
	}
	sort(edges, edges + m);

	int fr = 0; int to = 1;
	int cur = -1;

	for (int i = 0; i < m; i++) {
		if (!edges[i].first.second) {
			if (to > cur) {
				pos = 0;
				break;
			}
			u[edges[i].second] = fr;
			v[edges[i].second] = to;
			if (fr + 1 == to) {
				fr = 0;
				to++;
			}
			else {
				fr++;
			}
		}
		else {
			u[edges[i].second] = n - 1;
			v[edges[i].second] = ++cur;
		}
	}
	if (pos) {
		for (int i = 0; i < m; i++) {
			printf("%d %d\n", u[i] + 1, v[i] + 1);
		}
	}
	else {
		printf("%d", -1);
	}
}