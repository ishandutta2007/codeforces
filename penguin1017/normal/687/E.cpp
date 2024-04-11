#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=5e3+9;
vi g[N];
int cnt;
int deg[N],mini[N],dfn[N],low[N],in,id[N];
stack<int> S;
void tarjan(int n){
	dfn[n]=low[n]=++in;
	S.push(n);
	for(auto u:g[n]){
		if(id[u])continue;
		if(!low[u])tarjan(u);
		if(low[n]>=low[u])low[n]=low[u];
	}
	if(low[n]==dfn[n]){
		++cnt;
		while(S.size()){
			int u=S.top();
			if(low[u]>=low[n])id[u]=cnt,S.pop();
			else break;
		}
	}
}
bool vis[N];
int dep[N],sum[N];
queue<int> q;
int main(){
	int n,m;
	scanf("%d%d",&n,&m); 
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
	} 
	rep(i,1,n+1)if(!id[i])tarjan(i);
	rep(i,1,n+1){
		for(auto v:g[i]){
			if(id[i]!=id[v])deg[id[i]]++;
		}
		mini[i]=N;
	}
	rep(i,1,cnt+1)sum[i]=N;
	rep(i,1,n+1){
		memset(vis,0,sizeof vis);
		dep[i]=0;
		vis[i]=1;
		int ok=0;
		while(q.size())q.pop();
		q.push(i);
		while(q.size()){
			int u=q.front();
		//	cout<<u<<"check\n";
			q.pop();
			for(auto v:g[u]){
				if(!vis[v]){
					vis[v]=1;
					dep[v]=dep[u]+1;
					q.push(v);
				}
				else if(v==i){
					ok=1;
					mini[i]=dep[u]+1;
					break;
				}
			}
			if(ok)break;
		} 
		if(!ok)mini[i]=1;
		sum[id[i]]=min(sum[id[i]],mini[i]);
	}
	int ans=0,tot=n;
	rep(i,1,cnt+1){
		if(!deg[i]&&sum[i]>1){
			ans+=sum[i]*999+1;
			n-=sum[i];
		}
	}
	ans+=n;
	printf("%d\n",ans);
}