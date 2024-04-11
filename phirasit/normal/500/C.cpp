#include <stdio.h>
#include <algorithm>

#define N 510
#define M 1010

using namespace std;

int arr[M];
int w[N], idx[N];
int n, m;

int cmp(int a, int b) {
	int f = a, sum = 0, sum2 = 0, k = b;
	for(int i = 0;i < m;i++) {
		if(arr[i] == f) {
			f = (f == a ? b : a);
			sum += w[f];
		}
		if(arr[i] == k) {
			k = (k == a ? b : a);
			sum2 += w[k];
		}
	}
	return sum < sum2;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &w[i]);
		idx[i] = i;
	}
	for(int i = 0;i < m;i++) {
		scanf("%d", &arr[i]);
	}
	sort(idx+1, idx+n+1, cmp);
	int ans = 0;
	for(int i = 0;i < m;i++) {
		int p = 1;
		for(int j = 1;j <= n;j++) {
			if(idx[j] == arr[i]) {
				p = j;
				break;
			}
		}
		for(int j = p;j < n;j++) {
			ans += w[idx[j+1]];
			idx[j] = idx[j+1];
		}
		idx[n] = arr[i];
	}
	printf("%d\n", ans);
	return 0;
}