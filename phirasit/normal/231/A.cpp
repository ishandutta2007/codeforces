#include <stdio.h>

int main() {
	int n,ans = 0;
	int a,b,c;
	scanf("%d",&n);
	while(n--) {
		scanf("%d %d %d",&a,&b,&c);
		if(a + b + c >= 2)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}