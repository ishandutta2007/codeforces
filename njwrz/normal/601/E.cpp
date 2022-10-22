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
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
V<P<int,int> > in[1<<16];
int n,k,cnt;
P<int,int> p[20005];
int l[20005],r[20005];
int tap[30005];
int qu[30005];
int ans[30005];
void update(int x,int l,int r,int tl,int tr,P<int,int> px){
	if(l>=tl&&r<=tr){
		in[x].PB(px);
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,px);
	update(rc,mid+1,r,tl,tr,px);
}
int dp[1005],mod=1e9+7;
void solve(int x,int l,int r){
	int lst[1005];
	FOR(i,1,k)lst[i]=dp[i];
	for(auto u:in[x]){
		for(int i=k;i>=u.S;i--){
			gmax(dp[i],dp[i-u.S]+u.F);
		}
	}
	if(l==r){
		if(qu[l]){
			int op=1;
			FOR(i,1,k){
				ans[l]=(ans[l]+1ll*op*dp[i])%mod;
				op=1ll*op*10000019%mod;
			}
		}
		FOR(i,1,k)dp[i]=lst[i];
		RE;
	}
	int mid=(l+r)>>1;
	solve(lc,l,mid);
	solve(rc,mid+1,r);
	FOR(i,1,k)dp[i]=lst[i];
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S;
		l[i]=1;
	}
	cnt=n;
	int q;
	cin>>q;
	FOR(i,1,q){
		cin>>tap[i];
		if(tap[i]==1){
			cnt++;
			cin>>p[cnt].F>>p[cnt].S;
			l[cnt]=i;
		}else if(tap[i]==2){
			int x;
			cin>>x;
			r[x]=i;
		}else {
			qu[i]=1;
		}
	}
	FOR(i,1,cnt){
		if(!r[i])r[i]=q;
		update(1,1,q,l[i],r[i],p[i]);
	}
	solve(1,1,q);
	FOR(i,1,q){
		if(tap[i]==3){
			cout<<ans[i]<<'\n';
		}
	}
	RE 0;
}