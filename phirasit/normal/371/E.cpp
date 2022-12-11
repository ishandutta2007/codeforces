#include <stdio.h>
#include <algorithm>
#include <limits.h>

#define N 300010
#define INF LLONG_MAX

using namespace std;

long long sum[N];
int arr[N], idx[N];
int n, k;

int cmp(int a, int b) {
	return arr[a] < arr[b];
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
		idx[i] = i;
	}
	scanf("%d", &k);
	
	sort(idx, idx+n, cmp);
	
	for(int i = 0;i < n;i++) {
		if(i == 0) {
			sum[i] = arr[idx[i]];
		}else {
			sum[i] = arr[idx[i]] + sum[i-1];
		}
	}
	
	long long cnt = 0, ans = INF;
	int id;
	
	for(int i = 0;i < n;i++) {
		cnt += (long long) arr[idx[i]] * min(i, k-1) - sum[i-1];
		if(i-k >= 0) {
			cnt += sum[i-k];
			
			cnt -= (sum[i-1] - sum[i-k]) - (long long) (k-1) * arr[idx[i-k]];
		}
		if(i+1 >= k && cnt < ans) {
			ans = cnt;
			id = i;
		}
	}
	for(int j = id-k+1;j <= id;j++) {
		printf("%d ", idx[j] + 1);
	}
	printf("\n");
	return 0;
}