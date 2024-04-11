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
P<int,P<int,int> > p[200005];
int ans[200005],len,s[400005],k[200005];
int get(int x){
	int re=0;
	while(x){
		re+=s[x];
		x-=x&-x;
	}
	RE re;
}
void update(int x,int y){
	while(x<=len){
		s[x]+=y;
		x+=x&-x;
	}
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	V<int> v;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S.F;
		v.PB(p[i].F);
		v.PB(p[i].S.F);
		p[i].S.S=i;
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	len=v.size();
	FOR(i,1,n){
		p[i].F=lwb(ALL(v),p[i].F)-v.begin()+1;
		p[i].S.F=lwb(ALL(v),p[i].S.F)-v.begin()+1;
	}
	sort(p+1,p+n+1);
	FOR(i,1,n){
		ans[i]=-get(p[i].S.F);
		update(p[i].S.F+1,1);
	}
	FOR(i,1,n){
		ans[i]+=get(p[i].S.F);
		k[p[i].S.S]=ans[i];
	}
	FOR(i,1,n)cout<<k[i]<<'\n';
	RE 0;
}