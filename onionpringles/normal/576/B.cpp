#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> orbits[100001];
int single;
int u, v;
int vis[100001];
int perm[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", perm + i + 1);
	int orbcnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int cnt = 0;
		while (1) {
			if (vis[i]) break;
			vis[i] = 1;
			cnt++;
			orbits[orbcnt].push_back(i);
			i = perm[i];
		}
		orbcnt++;
	}
	int minsize = 100000000; int minind = -1;
	for (int i = 0; i < orbcnt; i++) {
		if (orbits[i].size() < minsize) {
			minsize = orbits[i].size();
			minind = i;
		}
	}
	if (minsize > 2) {
		puts("NO");
		return 0;
	}
	if (minsize == 2) {
		for (int i = 0; i < orbcnt; i++) {
			if (orbits[i].size() % 2 != 0) {
				puts("NO");
				return 0;
			}
		}
		puts("YES");
		int u = orbits[minind][0];
		int v = orbits[minind][1];
		printf("%d %d\n", orbits[minind][0], orbits[minind][1]);
		for (int i = 0; i < orbcnt; i++) {
			if (i == minind) continue;
			int sz = orbits[i].size();
			for (int j = 0; j < sz; j++) {
				if (j % 2) {
					printf("%d %d\n",orbits[i][j],v);
				}
				else {
					printf("%d %d\n", orbits[i][j], u);
				}
			}
		}
	}
	else {
		puts("YES");
		int u = orbits[minind][0];
		for (int i = 0; i < orbcnt; i++) {
			if (i == minind) continue;
			for(auto &x : orbits[i]){
				printf("%d %d\n", x, u);
			}
		}
	}
	return 0;
}