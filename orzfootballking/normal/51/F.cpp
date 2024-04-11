#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int d[2005],dp[2005],maxi,low[2005],siz[2005],col[2005];
bool vis[2005],used[2005];
V<int> v[2005],g[2005],now;
int sta[2005],top,cnv,num;
void dfs(int x,int fa){
	sta[++top]=x;now.PB(x);vis[x]=1;
	d[x]=++num;low[x]=d[x];
	for(auto u:v[x])if(u!=fa){
		if(d[u]){
			gmin(low[x],d[u]);
		}else{
			dfs(u,x);
			gmin(low[x],low[u]);
		}
	}
	if(low[x]==d[x]){
		cnv++;
		while(1){
			int t=sta[top--];
			siz[cnv]++;
			col[t]=cnv;
			if(t==x)break;
		}
	}
}
void get(int x,int fa){
	int m1=0,m2=0;
	for(auto u:g[x])if(u!=fa){
		get(u,x);
		if(dp[u]>m1){
			m2=m1;
			m1=dp[u];
		}else if(dp[u]>m2)m2=dp[u];
	}
	gmax(maxi,m1+m2+1);
	dp[x]=m1+1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	int ans=n;
	int cnt=0;
	FOR(i,1,n){
		if(!vis[i]){
			maxi=0;now.clear();cnv=0;num=0;top=0;
			dfs(i,-1);
			if(cnv==1)continue;
			for(auto u:now){
				for(auto nxt:v[u]){
					if(col[u]!=col[nxt]){
						g[col[u]].PB(col[nxt]);
						g[col[nxt]].PB(col[u]);
					}
				}
			}
			FOR(i,1,cnv){
				sort(ALL(g[i]));
				g[i].erase(unique(ALL(g[i])),g[i].end());
			}
			FOR(j,1,cnv){
				if(g[j].size()==1){
					ans--;
				}
			}
			get(1,-1);
			FOR(i,1,cnv)g[i].clear(),siz[i]=0;
			ans-=maxi-2;cnt++;
		}
	}
	ans+=cnt-1;
	cout<<ans;
	RE 0;
}