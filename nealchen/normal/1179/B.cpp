#include <stdio.h>
int main() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n+1-i; ++i) {
		int j, sw=1, x=i, y=1;
		for(j=m; j--; x=n+1-x, y+=sw*j, sw=-sw) printf("%d %d\n", x, y);
		if(i!=n+1-i) {
			for(j=1; j<m; x=n+1-x, sw=-sw, y+=sw*j, ++j) printf("%d %d\n", x, y);
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}