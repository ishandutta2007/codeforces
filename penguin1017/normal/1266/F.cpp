#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=5e5+9;
vi g[N],D[N];
int dep[N],maxn[N],maxn2[N],a[N],b[N],c[N],ans[N],ans2[N],vis[N];
void upd(int &a,int b){
	if(a<b)a=b;
}
void dfs(int u,int fa){
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		D[u].pb(dep[v]);
		if(dep[v]>maxn[u]){
			maxn2[u]=maxn[u],maxn[u]=dep[v];
		}
		else upd(maxn2[u],dep[v]);
	}
	sort(D[u].begin(),D[u].end()); 
	dep[u]=maxn[u];
	++dep[u];
}
void dfs2(int u,int fa){
	int tot1=0,sz1=D[u].size();
	for(auto w:D[u]){
		if(!vis[w])a[tot1++]=w;
		++vis[w];
	}
	for(auto v:g[u]){
		if(v==fa)continue;
		--vis[dep[v]];
		int tot2=0,sz2=D[v].size();
		for(auto w:D[v]){
			if(!vis[w])b[tot2++]=w;
			++vis[w];
		}
		int cnt=sz1+sz2-1,tot=0;
		rep(i,0,tot1)c[tot++]=a[i];
		rep(i,0,tot2)c[tot++]=b[i];
		sort(c,c+tot);
		rep(i,0,tot){
			int val=c[i];
			upd(ans2[val],cnt);
			cnt-=vis[val];
		}
		++vis[dep[v]];
		for(auto w:D[v])--vis[w];
	}
	for(auto w:D[u])--vis[w];
	for(auto v:g[u]){
		if(v==fa)continue;
		if(dep[v]==maxn[u]){
			int d=maxn2[u]+1;
			D[v].pb(d);
			if(d>maxn[v]){
				maxn2[v]=maxn[v],maxn[v]=d;
			}
			else upd(maxn2[v],d);
		}
		else{
			int d=maxn[u]+1;
			D[v].pb(d);
			maxn2[v]=maxn[v],maxn[v]=d;
		}
		dfs2(v,u);
	}
}
int main(){
	int n,u,v;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,-1);
	dfs2(1,-1);
	rep(i,1,n+1){
		sort(D[i].begin(),D[i].end());
		int last=-1,cnt=D[i].size();
		rep(j,0,D[i].size()){
			int val=D[i][j];
			if(val==last)continue;
			upd(ans[val<<1],cnt-j);
			if(j)upd(ans[(last<<1)+1],cnt-j+1);
			last=val;
		}
	}
	per(i,1,n)upd(ans[i],ans[i+1]);
	++ans[1];
	per(i,1,n)upd(ans2[i],ans2[i+1]);
	rep(i,1,n+1){
		if(i%2==0)upd(ans[i],ans2[i>>1]);
		if(!ans[i])ans[i]=1;
		printf("%d ",ans[i]);
	}
}