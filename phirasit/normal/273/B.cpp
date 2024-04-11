#include <stdio.h>
#include <algorithm>

#define N 100010
#define A first
#define B second

#define LL long long

using namespace std;

typedef pair<int, int> pii;

pii arr[2*N];
int n;

LL MOD;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i].A);
		arr[i].B = i;
	}
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i+n].A);
		arr[i+n].B = i;
	}
	scanf("%I64d", &MOD);
	sort(arr, arr + 2*n);
	LL ans = 1;
	for(int i = 0;i < 2*n;i++) {
		int j = i, cnt = 0, w = 1;
		while(j+1 < 2*n && arr[i].A == arr[j+1].A) {
			j++;
			if(arr[j].B == arr[j-1].B) {
				cnt++;
			}
			w++;
		}
		for(int k = 1;k <= w;k++) {
			LL val = (LL) k;
			while(cnt > 0 && val%2 == 0) {
				cnt--;
				val /= 2;
			}
			ans = (ans * val) % MOD;
		}
		i = j;
	}
	printf("%I64d\n", ans);
	return 0;
}