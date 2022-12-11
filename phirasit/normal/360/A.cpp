#include <stdio.h>
#include <limits.h>

#define INF LLONG_MAX
#define LIMIT 1000000000
#define N 5010

int command[N][4];
long long sum[N];
long long arr[N];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) {
		arr[i] = -INF;
		sum[i] = 0;
	}
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < 4;j++) {
			scanf("%d", &command[i][j]);
		}
	}
	for(int i = 0;i < m;i++) {
		int t = command[i][0];
		int a = command[i][1], b = command[i][2];
		long long d = command[i][3];
		if(t == 1) {
			for(int j = a;j <= b;j++) {
				sum[j] += d;
			}
		}else {
			for(int j = a;j <= b;j++) {
				if(arr[j] == -INF || arr[j] + sum[j] > d) {
					arr[j] = d - sum[j];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		sum[i] = 0;
		if(arr[i] == -INF) {
			arr[i] = -LIMIT;
		}
		if(arr[i] > LIMIT || -arr[i] > LIMIT) {
			printf("NO\n");
			return 0;
		}
	}
	for(int i = 0;i < m;i++) {
		int t = command[i][0];
		int a = command[i][1], b = command[i][2];
		long long d = command[i][3];
		if(t == 1) {
			for(int j = a;j <= b;j++) {
				sum[j] += d;
			}
		}else {
			long long mx = arr[a] + sum[a];
			for(int j = a + 1;j <= b;j++) {
				if(arr[j] + sum[j] > mx) {
					mx = arr[j] + sum[j];
				}
			}
			if(mx != d) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i = 1;i <= n;i++) {
		printf("%I64d ", arr[i]);
	}
	printf("\n");
	return 0;
}