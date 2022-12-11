#include <stdio.h>
#include <algorithm>

#define A first
#define B second

#define N 3010

using namespace std;

typedef pair<int, int> pii;

pii arr[N];
int bck[N];
int n, v;

int main() {
	scanf("%d%d", &n, &v);
	for(int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].A, &arr[i].B);
	}
	sort(arr, arr+n);
	int mx = 0;
	for(int i = 0;i < n;i++) {
		int d = arr[i].A, val = arr[i].B;
		if(val > v-bck[d]) {
			val -= v-bck[d];
			bck[d] = v;
		}else {
			bck[d] += val;
			val = 0;
		}
		if(val > v-bck[d+1]) {
			bck[d+1] = v;
		}else {
			bck[d+1] += val;
		}
		if(d+1 > mx) {
			mx = d+1;
		}
	}
	int ans = 0;
	for(int i = 0;i <= mx;i++) {
		ans += bck[i];
	}
	printf("%d\n", ans);
	return 0;
}