#include<cctype>
#include<cstdio>
const int maxn=300;
int a[maxn+10][maxn+10],n,b[maxn+10],ans[maxn+10]; bool vis[maxn+10];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			char c=getchar(); for(;!isgraph(c);c=getchar());
			a[i][j]=i==j||c=='1';
		}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) a[i][j]|=a[i][k]&&a[k][j];
	for(int i=1;i<=n;++i){
		int ans=1e5;
		for(int j=1;j<=n;++j) if(a[i][j]&&!vis[b[j]]&&b[j]<ans) ans=b[j];
		vis[ans]=1; printf("%d ",ans);
	}
	return 0;
}