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
int a[1000005],n,ans,num[1000005];
P<int,int> pl[500005],pr[500005];
int cntl,cntr;
int cnt[66];
int cc(int x){
	RE __builtin_popcount(x>>30)+__builtin_popcount(x-(x>>30)*(1<<30));
//	RE __builtin_popcount(x);
}
void solve(int l,int r){
	int lstans=ans;
	if(l==r)RE ;
	int mid=(l+r)>>1;
	cntl=cntr=0;
	int mi=1e18,mx=0;
	for(int i=mid;i>=l;i--){
		gmax(mx,a[i]);
		gmin(mi,a[i]);
		pl[++cntl]=MP(mi,mx);
	}
	mi=1e18,mx=0;
	FOR(i,mid+1,r){
		gmax(mx,a[i]);
		gmin(mi,a[i]);
		pr[++cntr]=MP(mi,mx);
	}
	int t=0;
	FOR(i,1,cntl){
		while(t<cntr&&(pr[t+1].F*2+1>=pl[i].F*2&&pr[t+1].S*2+1<=pl[i].S*2))t++;
		if(cc(pl[i].F)==cc(pl[i].S)){
			ans+=t;
		}
	}
	t=0;
	FOR(i,1,cntr){
		while(t<cntl&&(pl[t+1].F*2>=pr[i].F*2+1&&pl[t+1].S*2<=pr[i].S*2+1))t++;
		if(cc(pr[i].F)==cc(pr[i].S)){
			ans+=t;
		}
	}
	int tl=1,tr=1;
	FILL(cnt,0);
	FOR(i,1,cntl){
		while((pr[tl].F<<1)+1>pl[i].F<<1&&tl<=cntr){
			cnt[cc(pr[tl].S)]++;
			tl++;
		}
		while((pr[tr].S<<1)+1<pl[i].S<<1&&tr<=cntr){
			cnt[cc(pr[tr].S)]--;
			tr++;
		}
		if(tl>tr)ans+=cnt[cc(pl[i].F)];
	}
	tl=1,tr=1;
	FILL(cnt,0);
	FOR(i,1,cntr){
		while(pl[tl].F<<1>(pr[i].F<<1)+1&&tl<=cntl){
			cnt[cc(pl[tl].S)]++;
			tl++;
		}
		while(pl[tr].S*2<(pr[i].S<<1)+1&&tr<=cntl){
			cnt[cc(pl[tr].S)]--;
			tr++;
		}
		if(tl>tr)ans+=cnt[cc(pr[i].F)];
	} 
	solve(l,mid);solve(mid+1,r);
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;ans=n;
	FOR(i,1,n)cin>>a[i];
	solve(1,n);
	cout<<ans;
	RE 0;
}