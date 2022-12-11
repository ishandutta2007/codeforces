#include <stdio.h>

int n,m,k;

int main() {
	int ans = 0;
	scanf("%d %d %d",&n,&m,&k);
	while(n--) {
		int a;
		scanf("%d",&a);
		if(a == 1) {
			if(m > 0) {
				m--;
			}else {
				ans++;
			}
		}else {
			if(k > 0) {
				k--;
			}else if(m > 0) {
				m--;
			}else {
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}