#include <stdio.h>

#define N 2010

long long arr[N][N];
long long d1[2*N], d2[2*N];
long long s1, s2;
int n;

int main() {
	s1 = s2 = -1;
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			scanf("%I64d", &arr[i][j]);
			d1[i+j] += arr[i][j];
			d2[i-j+n] += arr[i][j];
		}
	}
	int x1, y1, x2, y2;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if((i+j)%2) {
				if(d1[i+j] + d2[i-j+n] - arr[i][j] > s1) {
					s1 = d1[i+j] + d2[i-j+n] - arr[i][j];
					x1 = j+1;
					y1 = i+1;
				}
			}else {
				if(d1[i+j] + d2[i-j+n] - arr[i][j] > s2) {
					s2 = d1[i+j] + d2[i-j+n] - arr[i][j];
					x2 = j+1;
					y2 = i+1;
				}
			}
		}
	}
	printf("%I64d\n%d %d %d %d\n", s1+s2, y1, x1, y2, x2);
	return 0;
}