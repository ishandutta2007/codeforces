#include<cstdio>
int n,x,cnt;
int vis[1000001];
int main(){
	scanf("%d",&n); printf("%d\n",n);
	for(int i=1;i<=n;++i) scanf("%d",&x), vis[x]=1;
	for(int i=1;i<=1000000;++i){
		if(!vis[i]) continue;
		if(!vis[1000001-i]) printf("%d ",1000001-i);
		else ++cnt;
	} cnt>>=1;
	for(int i=1;i<=1000000&&cnt;++i){
		if(!vis[i]&&!vis[1000001-i]) printf("%d %d ",i,1000001-i), --cnt;
	}
	return 0;
}