#include <stdio.h>
#include <map>
#include <set>

#define N 100010
#define INF (-1u/2)

using namespace std;

map<int, int> pos;
set<int> A, B;

int pass[N];
int state[N];

int p[N];
int n, a, b;
bool err = false;

int dfs(int u, int ls, int set) {
	if(pass[pos[u]]) {
		return 0;
	}
	pass[pos[u]] = 1;
	if(set == -1) {
		if(pos.find(a - u) != pos.end()) {
			return dfs(a - u, u, state[pos[u]] = set = 0) + 1;
		}else if(pos.find(b - u) != pos.end()) {
			return dfs(b - u, u, state[pos[u]] = set = 1) + 1;
		}
		return 1;
	}else {
		state[pos[u]] = set;
		if(a - u != ls) {
			if(pos.find(a - u) != pos.end()) {
				return dfs(a - u, u, set);
			}else {
				return 1;
			}
		}else {
			if(pos.find(b - u) != pos.end()) {
				return dfs(b - u, u, set);
			}else {
				return 1;
			}
		}
	}
	return -INF;
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	if(a == b) {
		b = INF;
	}
	for(int i = 0;i < n;i++) {
		state[i] = -1;
	}
	for(int i = 0;i < n;i++) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for(int i = 0;i < n;i++) {
		int u = p[i];
		if((2 * u == a) && (pos.find(b - u) == pos.end())) {
			state[i] = 0;
		}else if(pos.find(a - u) == pos.end() && 2 * u == b) {
			state[i] = 1;
		}else if((pos.find(a - u) == pos.end()) || (pos.find(b - u) == pos.end())) {
			int len = dfs(u, INF, -1);
			if(len%2) {
				err = true;
			}
		}
	}
	bool err = false;
	for(int i = 0;i < n;i++) {
		if(state[i] == -1) {
			err = true;
		}else if(state[i] == 0) {
			A.insert(p[i]);
		}else {
			B.insert(p[i]);
		}
	}
	for(int i = 0;i < n;i++) {
		if(state[i] == 0) {
			if(A.count(a - p[i]) == 0) {
				err = true;
			}
		}else if(state[i] == 1) {
			if(B.count(b - p[i]) == 0) {
				err = true;
			}
		}
	}
	if(err) {
		printf("NO\n");
	}else {
		printf("YES\n");
		for(int i = 0;i < n;i++) {
			printf("%d ", state[i]);
		}
		printf("\n");
	}
	return 0;
}