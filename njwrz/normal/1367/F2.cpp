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
int n,a[200005];
set<P<int,int> > s;
P<int,int> p1[200005],p2[200005];
bool cmp1(P<int,int> x,P<int,int> y){
	RE MP(x.F,y.S)<MP(y.F,x.S);
}
bool cmp2(P<int,int> x,P<int,int> y){
	RE MP(x.F,y.S)>MP(y.F,x.S);
}
bool check(P<int,int> x){
	swap(x.F,x.S);
	if(s.empty()){
		s.emplace(x);RE 1;
	}
	auto u=s.lwb(x);
	if((*u)==x)RE 1;
	if(u!=s.end()){
		if((*u).S<x.S)RE 0;
	}
	if(u!=s.begin()){
		u--;
		if((*u).S>x.S)RE 0;
	}
	s.emplace(x);
	RE 1;
}
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i],p1[i]=MP(a[i],i),p2[i]=MP(a[i],i);
	sort(p1+1,p1+n+1,cmp1);
	sort(p2+1,p2+n+1,cmp2);
	s.clear();
	int t;
	for(int i=n;i>=1;i--){
		if(!check(p2[i])){
			t=i;break;
		}
	}
	if(s.size()==n){
		cout<<0<<'\n';RE ;
	}
	int ans=t;
	FOR(i,1,n){
		P<int,int> now=p1[i];
		swap(now.F,now.S);
		s.erase(now);
		while(t&&check(p2[t]))t--;
		gmin(ans,t+i);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}