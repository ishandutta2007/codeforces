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
int cnt[500005],n,k,dp[500005],p[500005],mod=998244353,z[500005];
int l[500005],r[500005],x[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>k>>m;
	FOR(i,1,m){
		cin>>l[i]>>r[i]>>x[i];
		if(x[i]>=(1<<k)){
			cout<<0;RE 0;
		}
	}
	int ans=1,s,re,lt,rt;
	rep(t,0,k){
		V<P<int,int>> v;
		FILL(cnt,0);FILL(z,0);FILL(p,0);
		FOR(i,1,m){
			if(x[i]&(1<<t)){
				cnt[l[i]]++;
				cnt[r[i]+1]--;
			}else{
				v.PB(MP(l[i],r[i]));
			}
		}
		FOR(i,1,n)cnt[i]+=cnt[i-1],p[i]=p[i-1]+(!cnt[i]);
		for(auto &u:v){
			u.F=p[u.F-1]+1;
			u.S=p[u.S];
			if(u.F>u.S){
				cout<<0;RE 0;
			}
		}
		s=p[n];
		for(auto u:v)gmax(z[u.S],u.F);
		FILL(dp,0);
		lt=0;dp[0]=dp[1]=1;
		re=1;
		FOR(i,1,s){
			dp[i+1]=dp[i]*2%mod;
			rt=max(lt,z[i]);
			rep(j,lt,rt)dp[i+1]=(dp[i+1]-dp[j])%mod;
			dp[i+1]=(dp[i+1]+mod)%mod;
			lt=rt;
		}
		ans=ans*dp[s+1]%mod;
	}
	cout<<ans;
	RE 0;
}