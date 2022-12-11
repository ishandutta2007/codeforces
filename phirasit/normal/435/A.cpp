#include <stdio.h>

int n,m;
int cnt = 0;
int left;

int main() {
	scanf("%d%d",&n,&m);
	left = 0;
	while(n--) {
		int a;
		scanf("%d",&a);
		if(a <= left) {
			left -= a;
		}else {
			left = m-a;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}