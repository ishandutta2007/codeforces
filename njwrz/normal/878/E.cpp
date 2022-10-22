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
const int mod=1e9+7;
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int n,q,a[100005],sum[100005],pw[100005];
V<P<P<int,int>,int> > v;
int INF=1e12;
V<P<int,int> > query[100005];
int ans[100005];
V<int> pos;
int s[100005],invp[100005];
int get(int l,int r){
	RE (sum[r]-sum[l-1]+mod)*invp[l]%mod;
}
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];
	pw[0]=1;
	FOR(i,1,n)pw[i]=pw[i-1]*2%mod,invp[i]=POW(pw[i],mod-2);
	FOR(i,1,n){
		sum[i]=(sum[i-1]+pw[i]*(a[i]+mod))%mod;
	}
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;
		query[r].PB(MP(l,i));
	}
	FOR(i,1,n){
		P<P<int,int>,int> now=MP(MP(i,i),a[i]);
		int it=v.size();
		while(!v.empty()&&now.S>0){
			int val=now.S;
			FOR(j,v.back().F.F,v.back().F.S){
				val=val*2;if(val>INF)break;
			}
			val+=v.back().S;
			gmin(val,INF);
			now.S=val;
			now.F.F=v.back().F.F;
			v.pop_back();
			pos.pop_back();
		}
		v.PB(now);
		it=v.size();
		s[it]=(s[it-1]+get(now.F.F,now.F.S)*2)%mod;
		pos.PB(now.F.F);
		for(auto u:query[i]){
			int it=upb(ALL(pos),u.F)-pos.begin()-1;
			if(it<v.size()-1){
				ans[u.S]=(get(u.F,v[it].F.S)+s[v.size()]-s[it+1]+mod)%mod;
			}else{
				ans[u.S]=get(u.F,i);
			}
		}
	}
	FOR(i,1,q)cout<<ans[i]<<'\n';
	RE 0;
}