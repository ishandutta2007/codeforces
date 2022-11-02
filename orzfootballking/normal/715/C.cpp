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
int root,mx,S,inf=1e9,n,mod,vis[100005],used[100005],siz[100005];
int up[100005],down[100005],d[100005],pow10[100005],di[100005];
V<P<int,int> > v[100005];
map<int,int> mpu[100005],mpd[100005];
V<int> cl;
int get(int x){
	vis[x]=1;cl.PB(x);
	int son=0,ret=1;
	for(auto u:v[x]){
		if(!vis[u.F]){
			int t=get(u.F);
			ret+=t;
			gmax(son,t);
		} 
	}
	gmax(son,S-ret);
	if(son<mx){
		mx=son;root=x;
	}
	siz[x]=ret;
	RE ret;
}
void getud(int x,int ro,int fa){
	mpu[ro][up[x]]++;
	mpd[ro][(mod-down[x]*di[d[x]]%mod)%mod]++;
//	cout<<(mod-down[x]*di[d[x]]%mod)%mod<<' '<<down[x]<<' '<<d[x]<<" "<<x<<'\n';
	for(auto u:v[x]){
		if(!vis[u.F]&&u.F!=fa){
			down[u.F]=(down[x]*10+u.S)%mod;
			up[u.F]=(up[x]+pow10[d[x]]*u.S)%mod;
			d[u.F]=d[x]+1;
			getud(u.F,ro,x);
		}
	}
}
int getans(int x){
	d[x]=0;down[x]=up[x]=0;
	getud(x,x,0);
	int re=0;
	for(auto u:v[x])if(!vis[u.F]){
		down[u.F]=up[u.F]=u.S%mod;d[u.F]=1;
		getud(u.F,u.F,0);
	}
	for(auto u:v[x])if(!vis[u.F]){
		for(auto num:mpu[u.F]){
			re=re+mpd[x][num.F]*num.S;
			re=re-mpd[u.F][num.F]*num.S;
		}
	}
	for(auto u:v[x])mpd[u.F].clear(),mpu[u.F].clear();
	re=re+mpd[x][0]-1;
	mpd[x].clear();mpu[x].clear();
	RE re;
}
int ans;
void dfs(int x){
	vis[x]=1;
	ans+=getans(root);
//	cout<<root<<' '<<ans<<'\n';
	for(auto u:v[x]){
		if(!vis[u.F]){
			root=0;
			mx=inf;S=siz[u.F];
			get(u.F);
			for(auto num:cl)vis[num]=0;
			cl.clear();
			dfs(root);
		}
	}
}
int exgcd(int x,int y,int &x1,int &x2){
	if(!y){
		x1=1;x2=0;
		RE x;
	}
	int d=exgcd(y,x%y,x2,x1);
	x2-=x/y*x1;
	RE d;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	cin>>n>>mod;
	exgcd(mod,10,tmp,di[1]);
	di[1]=(di[1]+mod)%mod;
	pow10[0]=1;
	FOR(i,1,n)pow10[i]=pow10[i-1]*10%mod;
	di[0]=1;
	FOR(i,2,n)di[i]=di[i-1]*di[1]%mod;
	FOR(i,2,n){
		int x,y;
		int w;
		cin>>x>>y>>w;x++;y++;
		v[x].PB(MP(y,w));
		v[y].PB(MP(x,w));
	}
	mx=inf,S=n;
	get(1);
	FILL(vis,0);cl.clear();
	dfs(root);
	cout<<ans;
	RE 0;
}