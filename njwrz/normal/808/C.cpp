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
int a[105],ans[105];
P<int,int> p[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		ans[i]=a[i]/2+(a[i]%2);
		k-=ans[i];
	}
	if(k<0){
		cout<<-1;RE 0;
	}
	FOR(i,1,n){
		p[i]=MP(a[i],i);
	}
	sort(p+1,p+n+1,greater<P<int,int> >());
	FOR(i,1,n){
		int t=a[p[i].S]-ans[p[i].S];
		if(t<=k){
			ans[p[i].S]=a[p[i].S];
			k-=t;
		}else{
			ans[p[i].S]+=k;
			break;
		}
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}