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
P<int,P<int,int> > p[100005];
V<int> v[10005],s[10005];
int get(int col,int x){
	int re=0;
	while(x){
		re+=s[col][x];
		x-=x&-x;
	}
	RE re;
}
int get(int col,int l,int r){
	r=upb(ALL(v[col]),r)-v[col].begin();
	l=lwb(ALL(v[col]),l)-v[col].begin()+1;
	if(r>=l)RE get(col,r)-get(col,l-1);
	else RE 0;
}
void update(int col,int x){
	x=lwb(ALL(v[col]),x)-v[col].begin()+1;
	while(x<=v[col].size()){
		s[col][x]++;
		x+=x&-x;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>p[i].S.F>>p[i].F>>p[i].S.S;
		v[p[i].S.S].PB(p[i].S.F);
		p[i].F*=-1;
	}
	sort(p+1,p+n+1);
	FOR(i,1,10000){
		sort(ALL(v[i]));
		v[i].erase(unique(ALL(v[i])),v[i].end());
		s[i].resize(v[i].size()+1,0);
	}
	int ans=0;
	FOR(i,1,n){
		p[i].F*=-1;
		FOR(j,max(1ll,p[i].S.S-k),min(10000ll,p[i].S.S+k)){
			ans+=get(j,p[i].S.F-p[i].F,p[i].S.F+p[i].F);
		}
		update(p[i].S.S,p[i].S.F);
	}
	cout<<ans;
	RE 0;
}