#include <stdio.h>
#define MN 100000
#define MW 10
typedef long long LL;

int n,a[MN+5],pre[MN+5];
int val[MN+5],_valc[MN*MW+10];
int *valc = &_valc[MN+5];
LL ans;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	ans = 0;
	valc[0] = 1;
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1] + a[i];
		val[i] = pre[i] - i;
		ans += valc[val[i]];
		valc[val[i]]++;
	}
	for(int i=-n;i<=pre[n];i++){
		valc[i] = 0;
	}
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}