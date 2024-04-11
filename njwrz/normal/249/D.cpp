#include<bits/stdc++.h>
#define ll long long
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
int n,a,b,c,d;
P<ll,ll> p[100005];
bool cmp(P<int,int> x,P<int,int> y){
	if(x.F!=y.F){
		RE x.F<y.F;
	}else RE x.S>y.S;
}
int maxi[100005];
void update(int x,int y){
	while(x){
		gmax(maxi[x],y);
		x-=x&-x;
	}
}
int get(int x){
	int re=0;
	while(x<=n){
		gmax(re,maxi[x]);
		x+=x&-x;
	}
	RE re;
}
int dp[100005];
signed main(){
	scanf("%d %d/%d %d/%d",&n,&a,&b,&c,&d);
	V<ll> v1,v2;
	FOR(i,1,n){
		scanf("%lld%lld",&p[i].F,&p[i].S);
		ll t2=p[i].S*b*d-p[i].F*a*d;
		ll t1=p[i].S*b*d-p[i].F*c*b;
		if(!d){
			t2=p[i].S*b-p[i].F*a;
			t1=-1e18-1e9*p[i].F;
		}
		p[i]=MP(t1,t2);
		v1.PB(t1);
		v2.PB(t2);
	}
	sort(ALL(v1));
	v1.erase(unique(ALL(v1)),v1.end());
	sort(ALL(v2));
	v2.erase(unique(ALL(v2)),v2.end());
	FOR(i,1,n){
		p[i].F=lwb(ALL(v1),p[i].F)-v1.begin()+1;
		p[i].S=lwb(ALL(v2),p[i].S)-v2.begin()+1;
	}
	sort(p+1,p+n+1,cmp);
	int ans=0;
	FOR(i,1,n){
		if(p[i].F!=p[i-1].F&&i!=1){
			for(int j=i-1;j>=1;j--)if(p[j].F==p[i-1].F){
				update(p[j].S-1,dp[j]);
			}else break;
		}
		dp[i]=get(p[i].S)+1;
		if(v1[p[i].F-1]<=0&&v2[p[i].S-1]>=0){
			gmax(ans,dp[i]);
		}
	}
	cout<<ans;
	RE 0;
}