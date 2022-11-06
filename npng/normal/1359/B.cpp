#include <cstdio>
const int Maxn=100;
const int Maxm=1000;
int n,m,x,y;
char s[Maxn+5][Maxm+5];
bool vis[Maxn+5][Maxm+5];
const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&x,&y);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		if((x<<1)<=y){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(s[i][j]=='.'){
						ans+=x;
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]||s[i][j]!='.'){
					continue;
				}
				for(int k=0;k<1;k++){
					int nx=i+d[k][0],ny=j+d[k][1];
					if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny]||s[nx][ny]!='.'){
						continue;
					}
					vis[i][j]=vis[nx][ny]=1;
					ans+=y;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='.'&&!vis[i][j]){
					ans+=x;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}