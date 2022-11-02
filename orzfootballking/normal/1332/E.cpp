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
map<P<int,bool>,int> m;
int l,r,mod=998244353,cnt0,cnt1;
int POW(int x,bool f){
	if(m.count(MP(x,f)))RE m[MP(x,f)];
	if(x==1){
		if(f)RE m[MP(x,f)]=cnt1;
		else RE m[MP(x,f)]=cnt0;
	}
	int re=0;
	if(f){
		if(x&1){
			re=(re+POW(x/2,0)*POW(x/2,0)%mod*cnt1)%mod;
			re=(re+POW(x/2,1)*POW(x/2,0)%mod*cnt0*2)%mod;
			re=(re+POW(x/2,1)*POW(x/2,1)%mod*cnt1)%mod;
		}else{
			re=(re+POW(x/2,0)*POW(x/2,1)%mod*2)%mod;
		}
	}else{
		if(x&1){
			re=(re+POW(x/2,0)*POW(x/2,0)%mod*cnt0)%mod;
			re=(re+POW(x/2,1)*POW(x/2,0)%mod*cnt1*2)%mod;
			re=(re+POW(x/2,1)*POW(x/2,1)%mod*cnt0)%mod;
		}else{
			re=(re+POW(x/2,0)*POW(x/2,0)%mod)%mod;
			re=(re+POW(x/2,1)*POW(x/2,1)%mod)%mod;
		}
	}
	RE m[MP(x,f)]=re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	cin>>x>>y>>l>>r;
	cnt0=r/2-(l-1)/2;
	cnt1=(r-l+1)-cnt0;
	x*=y;
	if(x&1){
		int ans=1,s=r-l+1;
		while(x){
			if(x&1)ans=ans*s%mod;
			s=s*s%mod;
			x=x/2;
		}
		cout<<ans;
	}else{
		cout<<POW(x,0);
	}
	RE 0;
}