#include <stdio.h>
#include <algorithm>

#define N 200010
#define A first
#define B second
#define INF (-1u/2) - 1
using namespace std;

typedef pair<int, int> PII;

PII arr[2*N];

int a[N], b[N];
int n, m;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
		arr[i] = PII(a[i], 0);
	}
	scanf("%d", &m);
	for(int i = 0;i < m;i++) {
		scanf("%d", &b[i]);
		arr[i+n] = PII(b[i], 1);
	}
	sort(arr, arr+n+m);
	int mx = 0, mn = INF, cnt = 0;
	for(int i = -1;i <= n+m;i++) {
		if(i != -1 && i != n+m && arr[i].B == 0) {
			cnt++;
		}
		if(i+1 < n+m && arr[i].A == arr[i+1].A) {
			continue;
		}
		int f2p = cnt, f3p = n - f2p;
		int s2p = i+(i < n+m)-cnt, s3p = m - s2p;
		int fp = 2 * f2p + 3 * f3p, sp = 2 * s2p + 3 * s3p;
		if(fp-sp > mx-mn || (fp-sp == mx-mn && fp > mx)) {
			mx = fp;
			mn = sp;
		}
	}
	printf("%d:%d\n", mx, mn);
	return 0;
}