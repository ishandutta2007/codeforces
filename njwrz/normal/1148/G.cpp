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
#define sz(x) ((int)x.size())
using namespace std;
int n,k;
int lst[10000005];
int pri[10000005],a[100005];
V<P<int,int> > hav[100005];
int val[10000005];
V<int> g[100005];
int vis[100005];
struct DSU{
	int fa[100005];
	void init(int n){
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		g[x].PB(y);
		g[y].PB(x);
		x=get(x);y=get(y);
		fa[x]=y;
	}
}T;
void solve(int l,int r,V<int> node){
	if(l==r){
		for(auto u:node)T.merge(l,u);RE;
	}
	int mid=(l+r)>>1;
	FOR(i,l,mid)for(auto u:hav[i])val[u.F]++;
	V<int> vl,vr;
	for(auto t:node){
		int sum=0;
		for(auto u:hav[t])sum+=u.S*val[u.F];
		if(sum<mid-l+1)vl.PB(t);else vr.PB(t); 
	}
	FOR(i,l,mid)for(auto u:hav[i])val[u.F]--;
	if(!vl.empty())solve(l,mid,vl);
	if(!vr.empty())solve(mid+1,r,vr);
}
int ed[100005];
V<int> tp[100005];
P<int,int> p[100005];
int tot;
void dfs(int x){
	vis[x]=1;
	cout<<x<<' ';tot--;
	for(auto u:g[x])if(!vis[u]&&tot)dfs(u);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,2,10000000)pri[i]=1;
	FOR(i,2,10000000)if(pri[i]){
		lst[i]=i;
		for(int j=i+i;j<=10000000;j+=i)pri[j]=0,lst[j]=i;
	}
	FOR(i,1,n){
		cin>>a[i];
		V<int> num;
		int now=a[i];
		while(now!=1){
			num.PB(lst[now]);now/=lst[now];
		}
		sort(ALL(num));num.erase(unique(ALL(num)),num.end());
		int t=sz(num);
		rep(mask,1,1<<t){
			int now=1,mul=-1;
			rep(j,0,t)if(mask&(1<<j))now*=num[j],mul=-mul;
			hav[i].PB(MP(now,mul));
		}
	}
	int siz=0;
	V<int> node;
	FOR(i,1,n){
		int sum=0;
		for(auto u:hav[i])sum+=u.S*val[u.F];
		if(sum==siz){
			++siz;
			for(auto u:hav[i])val[u.F]++;
			node.PB(i);
		}
	}
	if(siz>=k){
		while(sz(node)>k)node.pop_back();
		for(auto u:node)cout<<u<<' ';RE 0;
	}
	FILL(val,0);
	FOR(i,1,n)for(auto u:hav[i])val[u.F]++;
	node.clear(); 
	FOR(i,1,n){
		int sum=0;
		for(auto u:hav[i])sum+=u.S*val[u.F];
		if(sum<n)node.PB(i);
		ed[i]=sum;
	}
	T.init(n);
	FILL(val,0);
	if(!node.empty())solve(1,n,node);
	FOR(i,1,n)tp[T.get(i)].PB(i);
	int mx=0;
	FOR(i,1,n)gmax(mx,sz(tp[i]));
	if(mx<=2){
		FOR(i,1,n)if(ed[i]<n-1){
			FOR(j,1,n)if(i!=j&&__gcd(a[i],a[j])==1)T.merge(i,j);
		}
	}
	FOR(i,1,n)p[i]=MP(sz(tp[i]),i);
	sort(p+1,p+n+1);reverse(p+1,p+n+1);
	int s=0,it=n;
	FOR(i,1,n){
		s+=p[i].F;
		if(s>=k){
			it=i;break;
		}
	}
	FOR(i,1,it){
		while(s>k&&p[i].F>2){
			s--;p[i].F--;
		}
	}
	FOR(i,1,it){
		tot=p[i].F;
		dfs(p[i].S);
	}
	RE 0;
}