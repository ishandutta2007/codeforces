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
int n,m;
int f[105][105];
P<int,int> p[105][105];
int dp[105][105];
int get(int l,int r){
	if(l>r)RE 0;
	int  &re=dp[l][r];
	if(re!=-1)RE re;
	FOR(mid,l,r){
		int cnt=0;
		FOR(i,1,n)if(p[i][mid].F>=l&&p[i][mid].S<=r)cnt++;
		gmax(re,get(l,mid-1)+get(mid+1,r)+cnt*cnt);
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		int len;
		cin>>len;
		FOR(j,1,len){
			int l,r;
			cin>>l>>r;
			FOR(k,l,r)p[i][k]=MP(l,r);
		}
	}
	FILL(dp,-1);
	cout<<get(1,m);
	RE 0;
}