#include <bits/stdc++.h>
int n, k, a[12345];
int query(int i, int j) {
	int a, b;
	printf("and %d %d\n", i, j);
	fflush(stdout);
	scanf("%d", &a);
	printf("or %d %d\n", i, j);
	fflush(stdout);
	scanf("%d", &b);
	return a+b;
}
int main() {
	scanf("%d%d", &n, &k);
	int u=query(2, 3), v=query(1, 3), w=query(1, 2);
	a[1]=(0ll+v+w-u)/2;
	a[2]=(0ll+u+w-v)/2;
	a[3]=(0ll+u+v-w)/2;
	for(int j=4; j<=n; ++j) a[j]=query(1, j)-a[1];
	std::sort(a+1, a+n+1);
	printf("finish %d\n", a[k]);
	fflush(stdout);
	return 0;
}