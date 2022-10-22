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
V<P<int,int> > v; 
void dfs(int x,int y){
	if(x==y)RE;
	int mid=(x+y)>>1;
	dfs(x,mid);dfs(mid+1,y);
	FOR(i,x,mid){
		v.PB(MP(i,mid+i-x+1));
	}
}
signed main(){
	int n;
	cin>>n;
	int t=1;
	while(t*2<=n)t*=2;
	dfs(1,t);dfs(n-t+1,n);
	cout<<v.size()<<'\n';
	for(auto u:v)cout<<u.F<<' '<<u.S<<'\n';
	RE 0;
}