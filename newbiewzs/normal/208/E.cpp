#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define pl pair<int,long long>
//#define int long long
using namespace std;
typedef long long ll;
const int N=2e5+55;
int n,m,x,y,deep[N],f[N],maxx[N];
vector<int>v[N],d[N];
int tem[N+N],*now=tem,*dep[N];
int son[N];
void dfs(int u,int fa){
	deep[u]=deep[fa]+1;maxx[u]=1;
	for(int i=0;i<v[u].size();i++){
		dfs(v[u][i],u);
		if(maxx[v[u][i]]>maxx[son[u]])son[u]=v[u][i];
	}
	maxx[u]=maxx[son[u]]+1;
}
int ans[N];
vector<pi>q[N],add[N];
pi g[N];
void calc(int u){
	for(int i=0;i<v[u].size();i++){
		deep[v[u][i]]=deep[u]+1;
		calc(v[u][i]);
		for(int k=0;k<d[deep[u]].size();k++){
			int id=d[deep[u]][k];
			int sd=deep[g[id].fi]-deep[u];
			add[u].push_back(mp(sd,id));
		//	kl[v[u][i]].push_back(mp(sd-1,id));
		}
		d[deep[u]].clear();
	}
	for(int i=0;i<q[u].size();i++){
		if(deep[u]<q[u][i].fi)continue;
		d[deep[u]-q[u][i].fi].pb(q[u][i].se);
	}
}
void dfs1(int u){
	dep[u][0]=1;
	if(son[u]){
		dep[son[u]]=dep[u]+1;
		dfs1(son[u]);
	}
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==son[u])continue;
		dep[v[u][i]]=now;
		now+=maxx[v[u][i]]+1;
		dfs1(v[u][i]);
		for(int k=1;k<=maxx[v[u][i]];k++){
			dep[u][k]+=dep[v[u][i]][k-1];
		}
	}
	for(int i=0;i<add[u].size();i++){
		int x=add[u][i].fi;
		int y=add[u][i].se;
		ans[y]+=dep[u][x];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		v[f[i]].pb(i);
	}
	for(int i=1;i<=n;i++){
		if(!f[i])dfs(i,0);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		q[x].pb(mp(y,i));
		g[i]=mp(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!f[i])deep[i]=1,calc(i);
	}
	for(int i=1;i<=n;i++){
		if(!f[i])
		{
			dep[i]=now;
			now+=maxx[i]+1;
			dfs1(i);
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]?ans[i]-1:0);
	}
	return 0;
}