#include <stdio.h>
#include <algorithm>

#define A first
#define B second
#define N 100010

using namespace std;

typedef pair<int, int> PII;

PII arr[N];
int n, r, avg;

int cmpB(PII a, PII b) {
	return a.B < b.B;
}
int main() {
	scanf("%d%d%d", &n, &r, &avg);
	for(int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].A, &arr[i].B);
	}
	sort(arr, arr+n, cmpB);
	long long pass = (long long) avg * n;
	long long ans = 0;
	for(int i = 0;i < n;i++) {
		pass -= arr[i].A;
	}
	for(int i = 0;i < n;i++) {
		if(r - arr[i].A <= pass) {
			ans += (long long) (r - arr[i].A) * arr[i].B;
			pass -= r - arr[i].A;
		}else if(pass > 0) {
			ans += (long long) pass * arr[i].B;
			pass = 0;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}