#include <stdio.h>

int a,b,t;

int main() {
	int ans;
	scanf("%d",&t);
	while(t--) {
		ans = 0;
		scanf("%d %d",&a,&b);
		while(a && b) {
			if(a < b) {
				ans += b/a;
				b %= a;
			}else {
				ans += a/b;
				a %= b;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}