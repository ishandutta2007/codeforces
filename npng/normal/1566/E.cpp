#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n;
bool leaf[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int f[Maxn+5];
int sum[Maxn+5];
int all_num;
void init_dfs(int u,int fa){
	leaf[u]=1;
	bool flag=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		flag=0;
		init_dfs(v,u);
		if(leaf[v]){
			leaf[u]=0;
		}
		f[u]+=f[v];
	}
	if(flag){
		all_num++;
	}
	sum[u]=f[u];
	if(!leaf[u]){
		f[u]++;
	}
	else if(!flag){
		f[u]--;
	}
}
int work_dfs(int u,int fa){
	int ans=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		ans=std::max(ans,work_dfs(v,u)+sum[u]-f[v]);
	}
	return ans;
}
void solve(){
	all_num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		f[i]=0;
		head[i]=0;
		leaf[i]=0;
	}
	tot=0;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs(1,0);
	int ans=all_num-work_dfs(1,0);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}