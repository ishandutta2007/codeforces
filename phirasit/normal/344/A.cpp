#include <stdio.h>

int n;

int main() {
	int i,a,b;
	int ans = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a);
		if(i == 0) {
			b = a;
			continue;
		}
		if(b != a) ans ++;
		b = a;
	}
	printf("%d\n",ans+1); 
	return 0;
}