#include <stdio.h>
#include <algorithm>

#define N 100010
#define LL long long

using namespace std;

LL arr[N];
LL dp1[N],dp2[N];
int n;

int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		scanf("%I64d",&arr[i]);
		dp1[i] = dp1[i-1] + arr[i];
	}
	sort(arr + 1,arr + n + 1);
	for(int i = 1;i <= n;i++) {
		dp2[i] = dp2[i-1] + arr[i];
	}
	int q;
	scanf("%d",&q);
	while(q--) {
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		if(t == 1) {
			printf("%I64d\n",dp1[b] - dp1[a-1]);
		}else {
			printf("%I64d\n",dp2[b] - dp2[a-1]);
		}
	}
	return 0;
}