#include <stdio.h>
#include <algorithm>

#define N 60
#define A first
#define B second

using namespace std;

typedef pair<int, int> pii;

pii z[N], x[N];
int p, q, l, r;

int main() {
	scanf("%d%d%d%d", &p, &q, &l, &r);
	for(int i = 0;i < p;i++) {
		scanf("%d%d", &z[i].A, &z[i].B);
	}
	for(int i = 0;i < q;i++) {
		scanf("%d%d", &x[i].A, &x[i].B);
	}
	int ans = 0;
	for(int i = l;i <= r;i++) {
		bool found = false;
		for(int j = 0;j < p;j++) {
			for(int k = 0;k < q;k++) {
				if(max(z[j].A, x[k].A + i) <= min(z[j].B, x[k].B + i)) {
					found = true;
				}
			}
		}
		if(found) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}