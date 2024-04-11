#include <bits/stdc++.h>
using namespace std;

int a[3000];
vector <int> op;

void AddOp(int x) {
	assert(x & 1);
	reverse(a + 1, a + x + 1);
	op.push_back(x);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			if ((i & 1) != (a[i] & 1)) {
				printf("-1\n");
				goto END;
			}
		}
		op.clear();
		for (int i = n - 1; i >= 2; i -= 2) {
			int x = i, y = i + 1;
			for (int j = 1; j <= n; j++) {
				if (a[j] == y) {
					AddOp(j);
					break;
				}
			}
			for (int j = 1; j <= n; j++) {
				if (a[j] == x) {
					AddOp(j - 1);
					AddOp(j + 1);
					AddOp(3);
					break;
				}
			}
			AddOp(i + 1);
		}
		for (int i = 1; i <= n; i++) {
			assert(a[i] == i);
		}
		printf("%d\n", (int)op.size());
		for (int i = 0; i < op.size(); i++) {
			printf("%d ", op[i]);
		}
		printf("\n");
		END:;
	}
	return 0;
}