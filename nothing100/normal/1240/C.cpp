#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
using namespace std;
int q,n,m;
LL f[500050][2],a[500050];
vector<pair<int,int> > edge[500050];
int cmp(LL x,LL y){return x>y;}
void dfs(int x,int y){
	f[x][0]=f[x][1]=0;
	for (int i=0;i<edge[x].size();i++)
	if (edge[x][i].fi!=y) dfs(edge[x][i].fi,x);
	int cnt=0;
	for (int i=0;i<edge[x].size();i++)
	if (edge[x][i].fi!=y){
		a[cnt++]=f[edge[x][i].fi][1]+edge[x][i].se-f[edge[x][i].fi][0];
		f[x][1]+=f[edge[x][i].fi][0];
	}
	sort(a,a+cnt,cmp);
	for (int i=0;i<cnt;i++){
		if (a[i]<=0) break;
		if (i==m-1){
			f[x][0]=f[x][1]+a[i];
			break;
		}
		else f[x][1]+=a[i];
	}
	f[x][0]=max(f[x][0],f[x][1]);
}
int main(){
	//freopen("C.in","r",stdin);
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) edge[i].clear();
		for (int i=1;i<n;i++){
			int o,p,t;
			scanf("%d%d%d",&o,&p,&t);
			edge[o].push_back(make_pair(p,t));
			edge[p].push_back(make_pair(o,t));
		}
		dfs(1,0);
		//for (int i=1;i<=4;i++) printf("%lld %lld\n",f[i][0],f[i][1]);
		printf("%lld\n",f[1][0]);
	}
}