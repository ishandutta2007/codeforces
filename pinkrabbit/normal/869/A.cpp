#include<cstdio>
int n,a[10001],y[10021],ans;
bool vis[10000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i), vis[a[i]]=1;
	for(int i=1;i<=n;++i) scanf("%d",y+i), vis[y[i]]=1;
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=n;++j)
			if(vis[a[i]^y[j]]) ++ans;
	if(ans&1) puts("Koyomi");
	else puts("Karen");
}