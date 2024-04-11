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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
const int mod=998244353;
int f[300005],inv[300005],finv[300005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
struct DSU{
	int fa[100005],siz[100005];
	void init(int n){
		FOR(i,1,n)fa[i]=i,siz[i]=1;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);y=get(y);
		fa[x]=y;
		siz[y]+=siz[x];
	}
}T;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,2*n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	T.init(n);
	int ans=1;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		int t1=T.siz[T.get(x)],t2=T.siz[T.get(y)];
		ans=ans*t1%mod*t1%mod*t2%mod*t2%mod;
//		cout<<t1<<' '<<t2<<'\n';
		ans=ans*(2*n-(i-1)*2-1)%mod;
		T.merge(x,y);
	}
	cout<<ans;
	RE 0;
}