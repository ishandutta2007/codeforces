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
const int maxn=1e3+5;
int n,m;
char s[maxn][maxn];
bool c1[maxn],c2[maxn];
bool vis[maxn][maxn];
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool inside(int x,int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int vx=x+dx[i],vy=y+dy[i];
		if(inside(vx,vy)&&s[vx][vy]=='#'&&!vis[vx][vy]) dfs(vx,vy);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		int flag=0;
		for(int j=0;j<m;j++)
			if(s[i][j]=='#'){
				if(flag==1){
					printf("-1\n");
					return 0;
				}
				flag=-1;
			}
			else if(flag==-1) flag=1;
	}
	for(int i=0;i<m;i++){
		int flag=0;
		for(int j=0;j<n;j++)
			if(s[j][i]=='#'){
				if(flag==1){
					printf("-1\n");
					return 0;
				}
				flag=-1;
			}
			else if(flag==-1) flag=1;
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++){
		c1[i]|=s[i][j]=='#';
		c2[j]|=s[i][j]=='#';
	}
	for(int i=0;i<n;i++) if(!c1[i]){
		bool flag=1;
		for(int j=0;j<m;j++) if(!c2[j]){
			flag=0;
			break;
		}
		if(flag){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=0;i<m;i++) if(!c2[i]){
		bool flag=1;
		for(int j=0;j<n;j++) if(!c1[j]){
			flag=0;
			break;
		}
		if(flag){
			printf("-1\n");
			return 0;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		if(s[i][j]=='#'&&!vis[i][j]){
			cnt++;
			dfs(i,j);
		}
	printf("%d\n",cnt);
	return 0;
}