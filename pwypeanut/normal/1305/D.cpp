#include <bits/stdc++.h>
using namespace std;

int N, sze[1005], cen;
vector<int> adjlist[1005];

int dfs(int x, int p) {
	sze[x] = 1;
	for (int i = 0; i < adjlist[x].size(); i++) {
		if (adjlist[x][i] == p) continue;
		sze[x] += dfs(adjlist[x][i], x);
	}
	if (cen == 0 && sze[x] * 2 >= N) {
		cen = x;
	}
	return sze[x];
}

int find_hotel(int x, int p, bool p1) {
	//printf("!!!!! %d %d\n", x, p);
	vector<int> v;
	for (int i = 0; i < adjlist[x].size(); i++) if (adjlist[x][i] != p) v.push_back(adjlist[x][i]);
	for (int i = 0; i < v.size() / 2; i++) {
		int a = v[i * 2], b = v[i*2+1];
		printf("? %d %d\n", a, b);
		fflush(stdout);
		int l;
		scanf("%d", &l); 
		if (l == a || l == b) {
			return find_hotel(l, x, 0);
		}
	}
	if (v.size() % 2 == 0) {
		if (!p1) return x;
		else {
			printf("? %d %d\n", p,x);
			fflush(stdout);
			int l;
			scanf("%d", &l); 
			return l;
		}
	}
	if (p1) {
		printf("? %d %d\n", p, v.back());
		fflush(stdout);
		int l;
		scanf("%d", &l); 
		if (l == x) return x;
		else if (l == p) return p;
		else return find_hotel(v.back(), x, 0);
	}
	return find_hotel(v.back(), x, 1);	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	dfs(1, -1);
	printf("! %d\n", find_hotel(cen, -1, 0));
}