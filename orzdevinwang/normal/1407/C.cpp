#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int n, a[N], las;
int main() {
	scanf("%d", &n);
	las = 1;
	for(int i = 2; i <= n; i++) {
		int aa, bb;
		printf("? %d %d\n", las, i);
		fflush(stdout);
		scanf("%d", &aa);
		printf("? %d %d\n", i, las);
		fflush(stdout);
		scanf("%d", &bb);
		if(aa < bb) {
			a[i] = bb;
		}
		else {
			a[las] = aa;
			las = i;
		}
	}
	a[las] = n;
	printf("! ");
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}