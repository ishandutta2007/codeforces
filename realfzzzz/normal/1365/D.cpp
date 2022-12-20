#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=50+5;
int n,m;
char s[maxn][maxn];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool inside(int x,int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}
bool vis[maxn][maxn];
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int vx=x+dx[i],vy=y+dy[i];
		if(inside(vx,vy)&&s[vx][vy]!='#'&&!vis[vx][vy]) dfs(vx,vy);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		n=readint();
		m=readint();
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		bool ok=1;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='B'){
			for(int k=0;k<4;k++){
				int vx=i+dx[k],vy=j+dy[k];
				if(inside(vx,vy)){
					if(s[vx][vy]=='G') ok=0;
					if(s[vx][vy]=='.') s[vx][vy]='#';
				}
			}
		}
		memset(vis,0,sizeof(vis));
		if(s[n-1][m-1]!='#') dfs(n-1,m-1);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++)
			if(s[i][j]=='G'&&!vis[i][j]) ok=0;
		printf(ok?"Yes\n":"No\n");
	}
	return 0;
}