#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 5000
int n,m,mi[MN+5],cnt[MN+5];
int main(){
	memset(mi,0x7f,sizeof(mi));
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(v<u) v+=n;
		cnt[u]++;
		mi[u]=std::min(mi[u],v-u);
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]==0) mi[i]=0;
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++)
			ans=std::max(ans,(cnt[j]-1)*n+(j-i)+mi[j]);
		for(int j=1;j<i;j++)
			ans=std::max(ans,(cnt[j]-1)*n+(n-i+j)+mi[j]);
		printf("%d ",ans);
	}
}