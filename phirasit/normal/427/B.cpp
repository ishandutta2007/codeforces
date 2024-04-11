#include <stdio.h>

#define N 200010

int arr[N],tmp[N];
int n,t,c;

int main() {
	scanf("%d%d%d",&n,&t,&c);
	for(int i = 0;i < n;i++) {
		scanf("%d",&arr[i]);
		tmp[i] = arr[i] <= t;
	}
	int ans = 0;
	for(int i = 0;i < n;i++) {
		if(i > 0 && tmp[i] > 0) {
			tmp[i] += tmp[i-1];
		}
		ans += tmp[i] >= c;
	}
	printf("%d\n",ans);
	return 0;
}