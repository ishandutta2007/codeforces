#include <stdio.h>

long long ans = 0;
int n,m;

int main() {
	int i,j;
	int a,b;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++) {
		scanf("%d",&a);
		if(i == 0) {
			ans += a-1;
		}else {
			if(a >= b) {
				ans += a-b;
			}else {
				ans += n+a-b;
			}
		}
		b = a;
	}
	printf("%I64d\n",ans);
	return 0;
}