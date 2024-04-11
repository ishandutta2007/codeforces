#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair(a,b)
#define F(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define nextInt(n) scanf("%d", &(n))

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

vector<int> adj[100000];
int cnt[100000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	nextInt(n);
	F(i, n - 1) {
		int u, v;
		nextInt(u); nextInt(v);
		u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	F(i, n) {
		if (adj[i].size() == 1) {
			int pst = i;
			int cur = adj[i][0];
			while (1) {
				if (adj[cur].size() == 1) {
					puts("Yes");
					return 0;
				}
				cnt[cur]++;
				if (adj[cur].size() > 2) break;
				int tmp = cur;
				cur = adj[cur][0] + adj[cur][1] - pst;
				pst = tmp;
			}
		}
	}
	F(i, n) {
		if (adj[i].size() < 3) continue;
		int bcnt = 0;
		for (auto &x : adj[i]) {
			if (adj[x].size() > 3 || adj[x].size() - 1 != cnt[x]) bcnt++;
		}
		if (bcnt > 2) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}