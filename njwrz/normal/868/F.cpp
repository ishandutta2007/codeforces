/*

DP





ll int
 dp 










*/
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
int dp[25][100005];
int n,k,L=1,R,ans,cnt[100005],a[100005],now;
void get(int l,int r){
	while(L>l){
		L--;
		ans+=cnt[a[L]];
		cnt[a[L]]++;
	}
	while(R<r){
		R++;
		ans+=cnt[a[R]];
		cnt[a[R]]++;
	}
	while(L<l){
		cnt[a[L]]--;
		ans-=cnt[a[L]];
		L++;
	}
	while(R>r){
		cnt[a[R]]--;
		ans-=cnt[a[R]];
		R--;
	}
}
void solve(int l,int r,int tl,int tr){
	int mid=(l+r)>>1;
	int it=0;
	dp[now][mid]=1e18;
	FOR(i,tl,min(mid-1,tr)){
		get(i+1,mid);
		if(dp[now][mid]>dp[now-1][i]+ans){
			dp[now][mid]=dp[now-1][i]+ans;
			it=i;
		}
	}
	mid=(l+r)>>1;
	if(mid>l)solve(l,mid-1,tl,it);
	if(mid<r)solve(mid+1,r,it,tr);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		get(1,i);
		dp[1][i]=ans;
	}
	FOR(i,2,k){
		now=i;
		solve(i,n,i-1,n-1);
	}
	cout<<dp[k][n];
	RE 0;
}