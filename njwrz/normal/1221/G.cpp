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
int n,m;
P<int,int> p[1005];
int val[45],mid;
struct DSU{
	int fa[85];
	void init(int n){
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);y=get(y);
		fa[x]=y;
	}
}T;
struct left{
	bool ok[1ll<<20];
	int g[20];
	void init(){
		rep(mask,0,1ll<<mid){
			ok[mask]=1;
			rep(i,0,mid)if(mask&(1ll<<i)){
				if(mask&g[i]){
					ok[mask]=0;break;
				}
			}
		}
	}
}L;
struct right{
	int val[1ll<<20];
	int g[20];
	void init(){
		int len=n-mid;
		rep(mask,0,1ll<<len){
			val[mask]=1;
			rep(i,0,len)if(mask&(1ll<<i)){
				if(mask&g[i]){
					val[mask]=0;break;
				}
			}
		}
		rep(i,0,len)rep(mask,0,1ll<<len)if(!(mask&(1ll<<i)))val[mask|(1ll<<i)]+=val[mask];
	}
}R;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(m<3){
		cout<<0;RE 0;
	}
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		p[i]=MP(x,y);
		x--;y--;
		val[x]|=1ll<<y;
		val[y]|=1ll<<x;
	}
	int ans=1ll<<n;
	int mul=1;
	rep(i,0,n)if(!val[i])mul=mul*2;
	ans+=mul*2;
	T.init(2*n);
	FOR(i,1,m){
		T.merge(p[i].F,p[i].S+n);
		T.merge(p[i].F+n,p[i].S);
	}
	int cnt=0;
	FOR(i,1,n){
		if(T.get(i)==T.get(i+n)){
			cnt=-1;break;
		}
		if(T.get(i)==i)cnt++;
		if(T.get(i+n)==i+n)cnt++;
	}
	if(cnt>=0){
		ans+=1ll<<(cnt/2);
	}
	T.init(n);
	FOR(i,1,m)T.merge(p[i].F,p[i].S);
	cnt=0;
	FOR(i,1,n)if(T.get(i)==i)cnt++;
	ans-=1ll<<cnt;
	mid=n/2;
	rep(i,0,mid)rep(j,0,mid)if(val[i]&(1ll<<j))L.g[i]|=1ll<<j;
	L.init();
	rep(i,0,n-mid)rep(j,0,n-mid)if(val[i+mid]&(1ll<<(j+mid)))R.g[i]|=1ll<<j;
	R.init();
	rep(mask,0,1ll<<mid)if(L.ok[mask]){
		int msk=1ll<<(n-mid);msk--;
		rep(i,0,mid)if(mask&(1ll<<i)){
			int to=(val[i]>>mid)^((1ll<<(n-mid))-1);
			msk&=to;
		}
		ans-=R.val[msk]*2;
	}
	cout<<ans;
	RE 0;
}