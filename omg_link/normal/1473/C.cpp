#include <stdio.h>
#include <algorithm>
#define MK 100000

int n,k,a[MK+5];

void solve(){
	scanf("%d%d",&n,&k);
	int l = k-(n-k);
	for(int i=1;i<=k;i++)
		a[i] = i;
	std::reverse(a+l,a+1+k);
	for(int i=1;i<=k;i++)
		printf("%d ",a[i]);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}