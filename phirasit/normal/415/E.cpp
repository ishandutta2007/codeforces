#include <stdio.h>

#define N 20

int arr[1 << N];
int tmp[1 << N];
long long total[N + 10];
long long sum[N + 10];
int n, m;

void div(int a, int b, int depth) {
	if(a >= b) {
		sum[depth] = 0;
		return;
	}
	int mid = (a+b)/2;
	div(a, mid, depth+1);
	div(mid+1, b, depth+1);
	int i = a, j = mid+1, t = a;
	total[depth] += (long long) (b-a+1)/2 * (b-a+1)/2;
	while(i <= mid && j <= b) {
		if(arr[i] <= arr[j]) {
			if(arr[i] == arr[j]) {
				total[depth]--;
			}
			tmp[t++] = arr[i++];
		}else {
			sum[depth] += (long long) mid-i+1;
			tmp[t++] = arr[j++];
		}
	}
	while(i <= mid) {
		tmp[t++] = arr[i++];
	}
	while(j <= b) {
		tmp[t++] = arr[j++];
	}
	for(i = a;i <= b;i++) {
		arr[i] = tmp[i];
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < (1<<n);i++) {
		scanf("%d", &arr[i]);
	}
	div(0, (1<<n)-1, 0);
	scanf("%d", &m);
	for(int i = 0;i < m;i++) {
		int q;
		scanf("%d", &q);
		for(int i = n-q;i <= n;i++) {
			sum[i] = total[i] - sum[i];
		}
		long long ans = 0;
		for(int i = 0;i <= n;i++) {
			ans += sum[i];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}