#include <vector>
#include <cstdio>
using namespace std;
const int Maxn=300000;
int fa[Maxn+5];
int n,m;
bool vis[Maxn+5],in[Maxn+5],del[Maxn+5];
vector<int> lis[Maxn+5];
int num;
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	num--;
	fa[fa_y]=fa_x;
}
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int qu[Maxn+5],qu_f,qu_t;
void work_bfs(){
	qu_f=1,qu_t=0;
	qu[++qu_t]=1;
	in[1]=vis[1]=1;
	for(int i=head[1];i;i=nxt[i]){
		int v=arrive[i];
		lis[1].push_back(v);
		vis[v]=1;
		del[v]=1;
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		if(in[u]){
			for(int i=0;i<(int)lis[u].size();i++){
				int v=lis[u][i];
				if(!del[v]){
					in[v]=1;
					for(int j=head[v];j;j=nxt[j]){
						int w=arrive[j];
						if(!vis[w]){
							vis[w]=1;
							del[w]=1;
							lis[v].push_back(w);
						}
					}
				}
				vis[v]=1;
				qu[++qu_t]=v;
			}
		}
		else{
			for(int i=head[u];i;i=nxt[i]){
				int v=arrive[i];
				if(vis[v]){
					continue;
				}
				vis[v]=1;
				if(!del[v]){
					in[v]=1;
					for(int j=head[v];j;j=nxt[j]){
						int w=arrive[j];
						if(!vis[w]){
							vis[w]=1;
							del[w]=1;
							lis[v].push_back(w);
						}
					}
				}
				qu[++qu_t]=v;
			}
		}
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		vis[i]=in[i]=del[i]=0;
		fa[i]=i;
		head[i]=0;
		lis[i].clear();
	}
	tot=0;
	num=n;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		merge(u,v);
	}
	if(num!=1){
		puts("NO");
		return;
	}
	in[1]=vis[1]=1;
	work_bfs();
	int len=0;
	for(int i=1;i<=n;i++){
		if(in[i]){
			len++;
		}
	}
	puts("YES");
	printf("%d\n",len);
	for(int i=1;i<=n;i++){
		if(in[i]){
			printf("%d ",i);
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}