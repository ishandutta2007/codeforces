#include <stdio.h>
#include <algorithm>

#define N 5

using namespace std;

int arr[N][N];
int p[N];

int main() {
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0;i < N;i++) {
		p[i] = i;
	}
	do {
		int cnt = 0;
		for(int i = 0;i < N;i++) {
			for(int j = i;j + 1 < N;j += 2) {
				cnt += arr[p[j]][p[j+1]] + arr[p[j+1]][p[j]];
			}
		}
		if(cnt > ans) {
			ans = cnt;
		}
	}while(next_permutation(p, p + N));
	printf("%d\n", ans);
	return 0;
}