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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int n,Q;
int it[500005],siz[1000005];
int it2[500005];
V<int> v[1000005],v2[1000005];
V<P<int,int> > add[1000005];
V<int> cl[1000005];
int lst[500005];
V<int> q[1000005];
struct bit{
	ll s[500005];
	void init(int n){
		FOR(i,1,n)s[i]=0;
	}
	void update(int x,int y){
		while(x<=Q){
			s[x]+=y;
			x+=x&-x;
		}
	}
	ll get(int x){
		ll re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
}T;
set<int> s;
int vis[1000005];
int isq[500005];
void dfs(int x,int y){
	vis[x]=1;
	for(auto u:cl[x])s.emplace(u);
	for(auto u:v2[x])if(u!=y)dfs(u,x);
	for(auto u:q[x]){
		auto it=s.lwb(u);
		if(it==s.begin()){
			lst[u]=0;
		}else {
			--it;
			lst[u]=*it;
		}
	}
	for(auto u:cl[x])s.erase(u);
}
ll ans[500005];
void dfs2(int x,int y){
	vis[x]=1;
	for(auto u:add[x])T.update(u.S,u.F);
	for(auto u:v[x])if(u!=y)dfs2(u,x);
	for(auto u:q[x])ans[u]=T.get(u)-T.get(lst[u]);
	for(auto u:add[x])T.update(u.S,-u.F);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>Q;
	int cnt=n,cnt2=n;
	FOR(i,1,n)it[i]=it2[i]=i,siz[i]=1;
	FOR(i,1,Q){
		char c;
		int x,y;
		cin>>c;
		if(c=='U'){
			cin>>x>>y;
			++cnt;
			siz[cnt]=siz[it[x]]+siz[it[y]];
			v[cnt].PB(it[x]);
			v[it[x]].PB(cnt);
			v[cnt].PB(it[y]);
			v[it[y]].PB(cnt);
			it[x]=cnt;
		}else if(c=='M'){
			cin>>x>>y;
			++cnt2;
			v2[cnt2].PB(it2[x]);
			v2[it2[x]].PB(cnt2);
			v2[cnt2].PB(it2[y]);
			v2[it2[y]].PB(cnt2);
			it2[x]=cnt2;
		}else if(c=='A'){
			cin>>x;
			add[it[x]].PB(MP(siz[it[x]],i));
		}else if(c=='Z'){
			cin>>x;
			cl[it2[x]].PB(i);
		}else {
			isq[i]=1;
			cin>>x;
			q[x].PB(i);
		}
	}
	for(int i=cnt2;i>=1;i--)if(!vis[i])dfs(i,-1);
	FILL(vis,0);
	for(int i=cnt;i>=1;i--)if(!vis[i])dfs2(i,-1);
	FOR(i,1,Q)if(isq[i])cout<<ans[i]<<'\n';
	RE 0;
}