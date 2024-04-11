#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=200010,O=500010;
#define INF (0x3f3f3f3f)
struct edge{
	int nxt,t;
}e[O<<1];
int head[N],edge_cnt;
void add_edge(int x,int y){
	e[edge_cnt]=(edge){head[x],y};
	head[x]=edge_cnt++;
}
int dfn[N],low[N],Tar_cnt,stk[N],stk_top,ID[N],VBC_cnt;
bool CutV[M];
vector<int>E[M];
void Tarjan(int x,int f){
	dfn[x]=low[x]=++Tar_cnt;
	stk[++stk_top]=x;
	int i,son=0;
	for (i=head[x];~i;i=e[i].nxt){
		int to=e[i].t;
		if (to==f){
			continue;
		}
		if (dfn[to]==0){
			son++;
			Tarjan(to,x);
			low[x]=min(low[x],low[to]);
			if (low[to]>=dfn[x]){
				CutV[x]=1;
				VBC_cnt++;
				int y;
				do{
					y=stk[stk_top--];
					ID[y]=VBC_cnt;
					E[VBC_cnt].push_back(y);
					E[y].push_back(VBC_cnt);
				}while (to!=y);
				ID[x]=VBC_cnt;
				E[VBC_cnt].push_back(x);
				E[x].push_back(VBC_cnt);
			}
		}else{
			low[x]=min(low[x],dfn[to]);
		}
	}
	if (f==0 && son<=1){
		CutV[x]=0;
	}
}
int n,fa[M],dep[M],siz[M],son[M],Top[M],Tid[M],dfs_cnt,sum[M];
void dfs_pre(int x,int f){
	sum[x]=sum[f];
	if (x<=n){
		sum[x]++;
	}
	fa[x]=f;
	dep[x]=dep[f]+1;
	siz[x]=1;
	int i;
	for (i=0;i<(int)E[x].size();i++){
		int to=E[x][i];
		if (to==f){
			continue;
		}
		dfs_pre(to,x);
		siz[x]+=siz[to];
		if (siz[to]>siz[son[x]]){
			son[x]=to;
		}
	}
}
void dfs_top(int x,int tp){
	Tid[x]=++dfs_cnt;
	Top[x]=tp;
	if (son[x]>0){
		dfs_top(son[x],tp);
	}
	int i;
	for (i=0;i<(int)E[x].size();i++){
		int to=E[x][i];
		if (to==fa[x] || to==son[x]){
			continue;
		}
		dfs_top(to,to);
	}
}
int LCA(int x,int y){
	while (Top[x]!=Top[y]){
		if (dep[Top[x]]<dep[Top[y]]){
			swap(x,y);
		}
		x=fa[Top[x]];
	}
	if (dep[x]<dep[y]){
		return x;
	}else{
		return y;
	}
}
int main(){
	int m,q,i;
	scanf("%d%d%d",&n,&m,&q);
	memset(head+1,-1,sizeof(int)*1*n);
	VBC_cnt=n;
	for (i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	Tarjan(1,0);
	dfs_pre(1,0);
	dfs_top(1,1);
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int g=LCA(x,y);
		int Ans=sum[x]+sum[y]-sum[g]*2;
		if (g>n){
			Ans--;
		}
		printf("%d\n",Ans);
	}
	return 0;
}