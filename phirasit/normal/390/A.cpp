#include <stdio.h>

#define N 110

int ver[N], hor[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ver[x]++;
		hor[y]++;
	}
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0;i < N;i++) {
		cnt1 += !!ver[i];
	}
	for(int i = 0;i < N;i++) {
		cnt2 += !!hor[i];
	}
	if(cnt1 < cnt2) {
		printf("%d\n", cnt1);
	}else {
		printf("%d\n", cnt2);
	}
	return 0;
}