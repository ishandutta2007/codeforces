#include <cstdio>
#include <cstring>
const int Maxn=5000;
const int Maxm=100000;
int n,m;
int n_1,n_2,n_3;
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int chos[Maxn+5][Maxn+5];
int col[Maxn+5];
int bel[Maxn+5],b_t;
int num[Maxn+5][2];
bool black[Maxn+5][2];
bool flag=1;
bool f[Maxn+5][Maxn+5];
void init_dfs(int u,int c){
	if(col[u]!=-1){
		if(col[u]==c){
			return;
		}
		flag=0;
		return;
	}
	bel[u]=b_t;
	col[u]=c;
	num[b_t][c]++;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		init_dfs(v,c^1);
		if(!flag){
			return;
		}
	}
}
int ans[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&n_1,&n_2,&n_3);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(col,-1,sizeof col);
	for(int i=1;i<=n;i++){
		if(col[i]==-1){
			b_t++;
			init_dfs(i,0);
		}
	}
	if(!flag){
		puts("NO");
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=b_t;i++){
		for(int j=0;j<=n;j++){
			if(f[i-1][j]){
				f[i][j+num[i][0]]=1;
				f[i][j+num[i][1]]=1;
				chos[i][j+num[i][0]]=0;
				chos[i][j+num[i][1]]=1;
			}
		}
	}
	if(f[b_t][n_2]==0){
		puts("NO");
		return 0;
	}
	for(int i=b_t,j=n_2;i>0;i--){
		black[i][chos[i][j]]=1;
		j-=num[i][chos[i][j]];
	}
	for(int i=1;i<=n;i++){
		if(black[bel[i]][col[i]]==1){
			ans[i]=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==0){
			if(n_1>0){
				n_1--;
				ans[i]=1;
			}
			else{
				ans[i]=3;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}