#pragma GCC optimize(2)
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
ll dp[17][100005],p[100005];
int tl,tr,B;
ll get(int l,int r){
	B=sqrt(r);
	ll re=0;
	FOR(i,l,B){
		re+=p[r/i];
	}
	gmax(l,B+1);
	FOR(i,1,B){
		tr=r/i,tl=r/(i+1)+1;
		gmax(tl,l);
		if(tl<=tr){
			re+=p[i]*(tr-tl+1);
		}
	}
	RE re;
}
void solve(int x,int l,int r,int tl,int tr){
	if(l>r)RE;
	int mid=(l+r)>>1,tm=-1;
	ll now=get(tl,mid); 
	dp[x][mid]=1e18;
	FOR(i,tl,min(tr,mid)){
		ll to=dp[x-1][i-1]+now;
		if(to<dp[x][mid]){
			dp[x][mid]=to;
			tm=i;
		}
		now-=p[mid/i];
	}
	solve(x,l,mid-1,tl,tm);
	solve(x,mid+1,r,tm,tr);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	p[1]=1;
	FOR(i,2,100000){
		p[i]=1ll*i*(i+1)/2-get(2,i);
	}
	FOR(i,1,100000){
		dp[0][i]=1e18;
	}
	FOR(i,1,16){
		solve(i,1,100000,1,100000);
	}
	int q;
	cin>>q;
	FOR(i,1,q){
		int x,y;
		cin>>x>>y;
		if(y>16){
			cout<<x<<'\n';
		}else cout<<dp[y][x]<<'\n';
	}
	RE 0;
}