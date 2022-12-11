#include <stdio.h>

int n;

int main() {
	int p = 0,cnt = 0;
	scanf("%d",&n);
	while(n--) {
		int c;
		scanf("%d",&c);
		if(c < 0) {
			cnt += (p <= 0);
			if(p > 0) p--;
		}else {
			p += c;
		}
	}
	printf("%d\n",cnt);
	return 0;
}