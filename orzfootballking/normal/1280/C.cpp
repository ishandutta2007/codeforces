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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<P<int,int> > v[200005];
int s[200005],n;
int dfsn(int p,int la){
	int re=0;
	s[p]=1;
	for(auto u:v[p]){
		if(u.F==la)continue;
		re=re+dfsn(u.F,p);
		if(s[u.F]&1)re=re+u.S;
		s[p]+=s[u.F];
	}
	RE re;
}
int dfsx(int p,int la){
	int re=0;
	s[p]=1;
	for(auto u:v[p]){
		if(u.F==la)continue;
		re=re+dfsx(u.F,p);
		re=re+min(s[u.F],n-s[u.F])*u.S;
		s[p]+=s[u.F];
	}
	RE re;
}
void solve(){
	cin>>n;
	n<<=1;
	FOR(i,1,n)v[i].clear();
	int x,y,z;
	rep(i,1,n){
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	cout<<dfsn(1,-1)<<' '<<dfsx(1,-1)<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}