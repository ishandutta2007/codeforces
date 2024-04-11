#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int inv[150005],n,mod=998244353,siz[150005],fa[150005],ch[150005],d[150005],sum[150005];
int in[150005],out[150005],hea[150005];
V<int> v[150005];
struct Bit{
	int s[150005];
	void add(int x,int y){
		while(x<=n){
			s[x]=(s[x]+y)%mod;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re=(re+s[x])%mod;
			x-=x&-x;
		}
		RE re;
	}
	void add(int x,int y,int val){
		add(x,val);
		add(y+1,-val);
	}
}T1,T2; 
void init(){
	inv[1]=1;
	FOR(i,2,n){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	}
}
void get(int p){
	siz[p]=1;
	for(auto u:v[p])if(fa[p]!=u){
		d[u]=d[p]+1;fa[u]=p;
		get(u);
		siz[p]+=siz[u];
	}
}
int cnt;
void dfs(int p,int head){
	in[p]=++cnt;
	hea[p]=head;
	ch[p]=0;
	for(auto u:v[p])if(u!=fa[p]){
		if(siz[u]>siz[ch[p]])ch[p]=u;
	}
	if(ch[p])dfs(ch[p],head);
	for(auto u:v[p])if(u!=fa[p]&&u!=ch[p]){
		dfs(u,u); 
	}
	out[p]=cnt;
}
int getans(int x){
	int re=0;
	re=re+(n-siz[x])*sum[x]%mod;
	while(x){
		re=(re+T2.get(in[x]-1)-T2.get(in[hea[x]]-1)+mod)%mod;
		x=hea[x];
		re=(re+(n-siz[x])*sum[fa[x]])%mod;
		x=fa[x];
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m; 
	init();
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	get(1);
	dfs(1,1);
	FOR(i,1,m){
		int f;
		cin>>f;
		if(f==1){
			cin>>x>>y;
			sum[x]=(sum[x]+y)%mod;
			T1.add(1,siz[x]*y%mod);
			T1.add(in[x]+1,out[x],-(siz[x]*y%mod));
			if(ch[x])T2.add(in[x],(n-siz[ch[x]])*y%mod);
		}else{
			cin>>x;
			int ans=T1.get(in[x]);
			ans=(ans+getans(x))%mod;
			ans=ans*inv[n]%mod;
			ans=(ans+mod)%mod;
			cout<<ans<<'\n';
		}
	}
	RE 0;
}