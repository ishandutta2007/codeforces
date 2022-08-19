#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,ans;
ll c[10][10],vis;
vector<pii> adj[200005];
set<pii> st[200005];

int id(pii x){
	return x.fi*(x.fi-1)/2+x.se;
}

void dfs(int now){
	if(now==k+1){
		return (void)(ans++);
	}
	for(int i=1;i<=now;i++){
		if(!((vis>>id(mp(now,i)))&1)){
			ll tmp=vis;
			vis|=c[now][i];
			dfs(now+1);
			vis=tmp;
		}
	}
}

int main(){
	n=readint(); m=readint(); k=readint();
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		adj[x].pb(mp(z,y));
	}
	for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			pii tmp=mp(adj[i].size(),j+1);
			if(st[adj[i][j].se].find(tmp)!=st[adj[i][j].se].end()) vis|=1ll<<id(tmp);
			st[adj[i][j].se].insert(tmp);
		}
	}
	for(int i=1;i<=n;i++){
		vector<pii> vec(0);
		for(auto x:st[i]) vec.pb(x);
		ll sh=0;
		for(int i=0;i<vec.size();i++) sh|=1ll<<id(vec[i]);
		for(int i=0;i<vec.size();i++) c[vec[i].fi][vec[i].se]|=sh;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}