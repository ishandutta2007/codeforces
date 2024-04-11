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
int a[2005],b[2005],c[2005],n,m,q,dp[2005][2005],mod=1e9+7; 
V<P<int,int> > g[2005];
P<int,int> p[2005],ran;
struct node{
	int l,r,id;
}range[2005];
bool cmp(node x,node y){
	RE x.l<y.l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	FOR(i,1,m){
		cin>>a[i]>>b[i]>>c[i];
		g[a[i]].PB(MP(b[i],c[i]));
		g[b[i]].PB(MP(a[i],c[i]));
	}
	FOR(i,2,n)dp[i][0]=-1e18;
	FOR(i,1,m){
		FOR(j,1,n){
			dp[j][i]=-1e18;
			for(auto u:g[j])gmax(dp[j][i],dp[u.F][i-1]+u.S);
		}
	}
	int ans=0;
	FOR(i,1,m){
		int t=-1e18;
		FOR(j,1,n)gmax(t,dp[j][i]);
		ans=(ans+t)%mod;
	}
	q-=m;
	if(!q){
		cout<<ans;RE 0;
	}
	FOR(i,1,m){
		p[i].S=c[i];
		p[i].F=-1e18;
		FOR(j,0,m){
			gmax(p[i].F,dp[a[i]][j]+(m-j)*c[i]);
			gmax(p[i].F,dp[b[i]][j]+(m-j)*c[i]);
		}
		p[i].F+=c[i];
	}
	int cnt=0;
	FOR(i,1,m){
		ran=MP(1,q);
		FOR(j,1,m){
			if(p[i].F>=p[j].F){
				if(p[i].S>=p[j].S)continue;
				else{
					gmin(ran.S,(p[i].F-p[j].F)/(p[j].S-p[i].S)+1);
				}
			}else{
				if(p[i].S<=p[j].S){
					ran=MP(q,-1);break;
				}else{
					gmax(ran.F,(p[j].F-p[i].F)/(p[i].S-p[j].S)+1+((p[j].F-p[i].F)%(p[i].S-p[j].S)!=0));
				}
			}
		}
		if(ran.F<=ran.S){
			range[++cnt]=(node){
				ran.F,ran.S,i
			};
		}
	}
	int last=0;
	sort(range+1,range+cnt+1,cmp);
	FOR(i,1,cnt){
		int l=max(range[i].l,last+1),r=range[i].r,id=range[i].id;
		if(l>r)continue;
		ans=(ans+(r-l+1)*((p[id].F+(l-1)*c[id]+p[id].F+(r-1)*c[id])%mod*500000004ll%mod))%mod;
		last=r;
	}
	cout<<ans;
	RE 0;
}