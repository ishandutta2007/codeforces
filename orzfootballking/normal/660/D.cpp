/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
int x[2005],y[2005];
P<int,int> p[4000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>x[i]>>y[i];
	}
	int ans=0,cnt=0;
	FOR(i,1,n){
		FOR(j,1,n)if(i!=j){
			int tx,ty;
			tx=x[i]-x[j];
			ty=y[i]-y[j];
			p[++cnt]=MP(tx,ty);
		}
	}
	sort(p+1,p+cnt+1);
	int len=cnt;
	cnt=0;
	FOR(i,1,len){
		if(i>1&&p[i]!=p[i-1]){
			ans+=cnt*(cnt-1)/2;
			cnt=1;
		}else cnt++;
	}
	ans+=cnt*(cnt-1)/2;
	cout<<ans/4;
	RE 0;
}