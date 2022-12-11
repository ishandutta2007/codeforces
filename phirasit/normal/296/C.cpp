#include <stdio.h>

#define MX_N 100010
#define LL long long

LL A[MX_N];
LL arr[MX_N];
LL op[MX_N][3];
LL cnt[MX_N];
int n,m,k;

int main() {
	int i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++) {
		scanf("%I64d",&arr[i]);
		A[i] = 0;
	}
	for(i=1;i<=m;i++) {
		scanf("%I64d %I64d %I64d",&op[i][0],&op[i][1],&op[i][2]);
	}
	while(k--) {
		int a,b;
		scanf("%d %d",&a,&b);
		cnt[a]++;
		cnt[b+1]--;
	}
	LL tmp = 0;
	for(i=1;i<=m;i++) {
		tmp += cnt[i];
		A[op[i][0]] += tmp * op[i][2];
		A[op[i][1]+1] -= tmp * op[i][2];
	}
	LL ans = 0;
	for(i=1;i<=n;i++) {
		ans += A[i];
		printf("%I64d ",ans + arr[i]);
	}
	printf("\n");
	return 0;
		
}