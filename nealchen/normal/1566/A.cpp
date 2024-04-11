#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
void work() {
	int n, s;
	scanf("%d%d", &n, &s);
	n=n-(n+1)/2+1;
	printf("%d\n", s/n);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}