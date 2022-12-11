#include <stdio.h>
#include <algorithm>

#define N 2010

using namespace std;

int idx[N];
int h[N];
int n;

int cmp(int a, int b) {
	return h[a] < h[b];
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &h[i]);
		idx[i] = i;
	}
	sort(idx, idx+n, cmp);
	int cnt = 1;
	for(int i = 0;i < n;i++) {
		while(i+1 < n && h[idx[i]] == h[idx[i+1]]) {
			cnt++;
			i++;
		}
	}
	if(cnt < 3) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	cnt = 1;
	for(int i = 0;i < n;i++) {
		printf("%d ", idx[i]+1);
	}
	printf("\n");
	for(int i = 0;i < n-1;i++) {
		if(h[idx[i]] == h[idx[i+1]]) {
			if(cnt >= 3) {
				break;
			}
			for(int j = 0;j < n;j++) {
				if(j == i) {
					printf("%d ", idx[j+1]+1);
				}else if(j == i+1) {
					printf("%d ", idx[j-1]+1);
				}else {
					printf("%d ", idx[j]+1);
				}
			}
			printf("\n");
			cnt++;
		}
	}
	return 0;
}