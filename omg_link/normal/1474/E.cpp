#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,a[MN+5];
long long sum;

void swap(int x,int y){
	sum += 1ll*(x-y)*(x-y);
	std::swap(a[x],a[y]);
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		a[i] = i;
	sum = 0;
	swap(1,n);
	for(int i=2;i<=n/2;i++)
		swap(n,i);
	for(int i=n/2+1;i<=n-1;i++)
		swap(1,i);
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
	printf("%d\n",n-1);
	for(int i=n-1;i>=n/2+1;i--)
		printf("%d %d\n",i,1);
	for(int i=n/2;i>=2;i--)
		printf("%d %d\n",i,n);
	printf("%d %d\n",1,n);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}