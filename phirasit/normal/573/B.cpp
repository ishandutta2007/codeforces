#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 100010;
const int inf = -1u/2;

int arr[N], mn[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
		mn[i] = inf;
	}
	int m = 1;
	for(int i = 0;i < n;i++) {
		m = min(m, arr[i] - i);
		mn[i] = i + m;
	}
	m = n;
	for(int i = n-1;i >= 0;i--) {
		m = min(m, i + arr[i]);
		mn[i] = min(mn[i], m - i);
	}
	int ans = 0;
	for(int i = 0;i < n;i++) {
		ans = max(ans, mn[i]);
	}
	printf("%d\n", ans);
	return 0;
}