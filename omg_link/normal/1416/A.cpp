#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 300000

int n,a[MN+5],ls[MN+5],mx[MN+5],rk[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ls[i] = 0;
		mx[i] = 0;
		rk[i] = i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx[a[i]] = std::max(mx[a[i]],i-ls[a[i]]);
		ls[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		mx[i] = std::max(mx[i],n+1-ls[i]);
	}
	std::sort(rk+1,rk+1+n,[](int a,int b)->bool{
		return mx[a]<mx[b];
	});
	int lsp = 1;
	int ans = 0x3fffffff;
	for(int i=1;i<=n;i++){
		if(rk[i]<ans){
			int num = rk[i];
			for(int i=lsp;i<=mx[num]-1;i++)
				printf("%d ",ans==0x3fffffff?-1:ans);
			ans = num;
			lsp = mx[num];
		}
	}
	for(int i=lsp;i<=n;i++)
		printf("%d ",ans==0x3fffffff?-1:ans);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}