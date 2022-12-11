#include <stdio.h>

int n, m;

int main() {
	int mx = 0,id;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) {
		int val;
		scanf("%d", &val);
		int p = (val + m-1) / m;
		if(p >= mx) {
			mx = p;
			id = i;
		}
	}
	printf("%d\n", id);
	return 0;
}