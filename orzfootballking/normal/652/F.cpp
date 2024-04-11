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
int ans[300005];
int t[300005];
P<int,char> p[300005];
map<int,int> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S;
		p[i].F--;
		mp[p[i].F]=i;
	}
	sort(p+1,p+n+1);
	int begin=0;
	FOR(i,1,n){
		if(p[i].S=='R'){
			begin=((begin-(k+p[i].F)/m)%n+n)%n;
			ans[i]=(p[i].F+k)%m;
		}else{
			begin=(begin+(m-p[i].F-1+k)/m)%n;
			ans[i]=((p[i].F-k)%m+m)%m;
		}
	}
	sort(ans+1,ans+n+1);
	FOR(i,begin+1,n){
		t[mp[p[i].F]]=ans[i-begin];
	}
	FOR(i,1,begin){
		t[mp[p[i].F]]=ans[n-begin+i];
	}
	FOR(i,1,n)cout<<t[i]+1<<' ';
	RE 0;
}