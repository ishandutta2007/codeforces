#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[100010];
set <pii> S;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, x; scanf("%d%d%d", &n, &m, &x);
		S.clear();
		for (int i = 0; i < m; i++) S.insert(mp(0, i + 1));
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			int x = a[i];
			printf("%d ", S.begin()->se);
			pii tmp = *S.begin(); S.erase(S.begin());
			S.insert(mp(tmp.fi + x, tmp.se));
		}
		printf("\n");
	}
	return 0;
}