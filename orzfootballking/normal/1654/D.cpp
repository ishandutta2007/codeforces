#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
V<int> v[200005];
int pri[200005],lst[200005],n;
struct node{
	int to,x,y;
};
V<node> g[200005];
int cnt[200005],mini[200005],inv[200005],val[200005];
void dfs(int x,int y){
	for(auto u:g[x])if(u.to!=y){
		for(auto tu:v[u.x]){
			cnt[tu]--;
			gmin(mini[tu],cnt[tu]);
		}
		for(auto tu:v[u.y])cnt[tu]++;
		dfs(u.to,x);
		for(auto tu:v[u.x])cnt[tu]++;
		for(auto tu:v[u.y])cnt[tu]--;
	}
}
int mod=998244353;
void dfs2(int x,int y){
	for(auto u:g[x])if(u.to!=y){
		val[u.to]=val[x]*inv[u.x]%mod*u.y%mod;
		dfs2(u.to,x);
	}
}
void solve(){
	cin>>n;
	FOR(i,1,n)g[i].clear();
	FOR(i,1,n)mini[i]=cnt[i]=0;
	FOR(i,2,n){
		int fr,to,x,y;
		cin>>fr>>to>>x>>y;
		int t=__gcd(x,y);
		x/=t;y/=t;
		g[fr].PB((node){
			to,x,y
		});
		g[to].PB((node){
			fr,y,x
		});
	}
	dfs(1,-1);
	val[1]=1;
	FOR(i,1,n){
		FOR(j,1,-mini[i]){
			val[1]=val[1]*i%mod;
		}
	}
//	cout<<val[1]<<'\n';
	dfs2(1,-1);
	int ans=0;
	FOR(i,1,n)ans=(ans+val[i])%mod;
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,2,200000)pri[i]=1;
	inv[1]=1;
	FOR(i,2,200000){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		if(pri[i]){
			for(int j=i;j<=200000;j+=i){
				pri[j]=0;
				lst[j]=i;
			}
		}
	}
	FOR(i,2,200000){
		int now=i;
		while(now>1){
			v[i].PB(lst[now]);
			now=now/lst[now];
		}
	}
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}