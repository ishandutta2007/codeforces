#include <stdio.h>

int n;

int main() {
	int i,ch = 0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		if(n%i == 0) {
			int j = i;
			int b = 0;
			while(j) {
				if(j%10 != 4 && j%10 != 7) b = 1;
				j /= 10;
			}
			if(b == 0) ch = 1;
		}
	}
	if(ch) {
		printf("YES\n");
	}else {
		printf("NO\n");
	}
	return 0;
}