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
#define sz(x) ((int)x.size())
using namespace std;
P<int,int> dp1[300005],dp2[300005];
int dp[300005],n,a[300005],b[300005];
map<int,int> mp,lsta,lstb;
map<int,P<int,int> > mp1,mp2;
struct bit{
	P<int,int> s[300005];
	void update(int x,P<int,int> y){
		x++;
		while(x<=n+1){
			gmax(s[x],y); 
			x+=x&-x;
		}
	}
	P<int,int> get(int x){
		x++;
		P<int,int> re=MP(-1,-1);
		while(x){
			gmax(re,s[x]);
			x-=x&-x;
		}
		RE re;
	}
}T1,T2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i],a[i]+=a[i-1];
	FOR(i,1,n)cin>>b[i],b[i]+=b[i-1];
	mp[0]=0;mp1[0]=MP(0,0);mp2[0]=MP(0,0);lsta[0]=lstb[0]=0;
	FOR(i,1,n){
		if(mp.count(a[i]+b[i])){
			dp[i]=mp[a[i]+b[i]]+1;
		}
		gmax(dp[i],dp[i-1]);
		dp1[i]=dp1[i-1];dp2[i]=dp2[i-1];
		if(mp1.count(a[i]))gmax(dp1[i],MP(mp1[a[i]].F+1,mp1[a[i]].S));
		if(mp2.count(b[i]))gmax(dp2[i],MP(mp2[b[i]].F+1,mp2[b[i]].S));
		int it=-1;
		if(lsta.count(a[i])){
			it=lsta[a[i]];
			P<int,int> now=T1.get(it);
			gmax(dp1[i],MP(now.F+1,now.S));
		}
		if(lstb.count(b[i])){
			it=lstb[b[i]];
			P<int,int> now=T2.get(it);
			gmax(dp2[i],MP(now.F+1,now.S));
		}
		if(lsta.count(a[i])){
			if(-dp2[i].S<=lsta[a[i]])gmax(dp[i],dp2[i].F+1);
		}
		if(lstb.count(b[i])){
			if(-dp1[i].S<=lstb[b[i]])gmax(dp[i],dp1[i].F+1);
		}
		P<int,int> now=MP(dp[i],-i);
		gmax(dp1[i],now);gmax(dp2[i],now);
		gmax(mp1[a[i]],dp1[i]);gmax(mp2[b[i]],dp2[i]);
		gmax(mp[a[i]+b[i]],max({dp[i],dp1[i].F,dp2[i].F}));
		T1.update(-dp2[i].S,MP(dp2[i].F,-i));
		T2.update(-dp1[i].S,MP(dp1[i].F,-i));
		lsta[a[i]]=i;lstb[b[i]]=i;
	}
	int ans=0;
	FOR(i,1,n){
		gmax(ans,dp[i]);
		gmax(ans,dp1[i].F);
		gmax(ans,dp2[i].F);
	}
	cout<<ans;
	RE 0;
}