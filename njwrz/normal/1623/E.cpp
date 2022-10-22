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
int n,k;
int lc[200005],rc[200005];
char c[200005];
bool use[200005];
int dfn[200005],dfr[200005];
int cnt,len,fa[200005];
int node[200005];
int dep[200005];
void dfs(int x){
	dfn[x]=++cnt;
	if(lc[x])dep[lc[x]]=dep[x]+1,fa[lc[x]]=x,dfs(lc[x]);
	node[++len]=x;
	if(rc[x])dep[rc[x]]=dep[x]+1,fa[rc[x]]=x,dfs(rc[x]);
	dfr[x]=cnt;
}
bool f[200005];
struct bit{
	int sum[200005];
	void update(int x,int y){
//		assert(x>0);
		while(x<=n){
			sum[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=sum[x];
			x-=x&-x;
		}
		RE re;
	}
}T1,T2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>c[i];
	FOR(i,1,n){
		cin>>lc[i]>>rc[i];
	}
	dep[1]=1;
	dfs(1);
	for(int i=n-1;i>=1;i--){
		if(c[node[i+1]]>c[node[i]])f[node[i]]=1;
		else if(c[node[i+1]]==c[node[i]])f[node[i]]=f[node[i+1]];
	}
	FOR(i,1,n)if(!use[node[i]]){
		int x=node[i];
		bool ff=0;
		if(f[x]){
			if(T1.get(dfn[x])==0&&dep[x]-T2.get(dfn[x])<=k){
				ff=1;
			}
		}
		if(ff){
			while(x&&!use[x]){
				T2.update(dfn[x],1);T2.update(dfr[x]+1,-1);
				use[x]=1;
				x=fa[x];
				k--;
			}
		}else{
			T1.update(dfn[x],1);
			T1.update(dfr[x]+1,-1);
		}
	}
	FOR(i,1,n)if(use[node[i]]){
		cout<<c[node[i]]<<c[node[i]];
	}else cout<<c[node[i]];
	RE 0;
}