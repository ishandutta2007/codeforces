#include<cstdio>
const int maxn=1000;
int n,m,w[maxn+10],op[maxn+10],lst[maxn+10],cnt,ans;
bool vis[maxn+10];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&w[i]);
	for(int i=1;i<=m;++i){
		scanf("%d",&op[i]);
		if(!vis[op[i]]) lst[++cnt]=op[i],vis[op[i]]=1;
	}
	for(int i=1;i<=n;++i) if(!vis[i]) lst[++cnt]=i;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j) if(lst[j]==op[i]){
			for(int k=j-1;k>=1;--k) lst[k+1]=lst[k]; lst[1]=op[i];
			break;
		}else ans+=w[lst[j]];
	printf("%d",ans); return 0;
}