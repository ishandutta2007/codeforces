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
int a[100005],b[100005],p[100005],n;
V<P<int,int> > v[100005]; 
void dfs(int x){
	for(auto u:v[x]){
		dfs(u.F);
		if(p[u.F]>=0)p[x]+=p[u.F];
		else {
			if(p[u.F]<-1e18/u.S){
				cout<<"NO";exit(0);
			}
			p[x]+=p[u.F]*u.S; 
		}
		if(p[x]<-1e18){
			cout<<"NO";exit(0);
		}
	}
	p[x]+=b[x]-a[x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>b[i];
	FOR(i,1,n)cin>>a[i];
	int x,y;
	FOR(i,2,n){
		cin>>x>>y;
		v[x].PB(MP(i,y));
	}
	dfs(1);
	if(p[1]>=0){
		cout<<"YES";
	}else cout<<"NO";
	RE 0;
}