#include <bits/stdc++.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int c, d;
		scanf("%d%d", &c, &d);
		if((c+d)%2==1) {
			puts("-1");
		} else if(c==0&&d==0) {
			puts("0");
		} else if(c==d) {
			puts("1");
		} else {
			puts("2");
		}
	}
	return 0;
}