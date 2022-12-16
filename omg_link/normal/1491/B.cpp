#include <stdio.h>
#include <algorithm>
#define MN 100

int n,u,v,a[MN+5];

void solve(){
	scanf("%d%d%d",&n,&u,&v);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int type = 0;
	for(int i=2;i<=n;i++){
		type = std::max(type,std::abs(a[i]-a[i-1]));
	}
	if(type>=2){
		puts("0");
	}else if(type==1){
		printf("%d\n",std::min(u,v));
	}else{
		printf("%d\n",v+std::min(u,v));
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}