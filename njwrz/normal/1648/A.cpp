#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int a[100005],n,m;
int get(int x,int y){
	RE (x-1)*m+y;
}
V<P<int,int> > v[100005]; 
struct Bit{
	int s[100005];
	void update(int x,int y){
		while(x<=n*m){
			s[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
}T1,T2,T3,T4;
int solve(int x){
	int re=0;
//	cout<<x<<'\n';
	for(auto u:v[x]){
//		cout<<u.F<<' '<<u.S<<'\n';
		T1.update(u.S,u.F+u.S);
		T2.update(u.S,1);
		re+=T2.get(u.S)*(u.F+u.S);
		re-=T1.get(u.S);
		T3.update(u.S,u.F-u.S);
		T4.update(u.S,1);
		re+=(T4.get(n*m)-T4.get(u.S))*(u.F-u.S);
		re-=(T3.get(n*m)-T3.get(u.S));
	}
	for(auto u:v[x]){
		T1.update(u.S,-u.F-u.S);
		T2.update(u.S,-1);
		T3.update(u.S,-u.F+u.S);
		T4.update(u.S,-1);
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	V<int> num;
	FOR(i,1,n)FOR(j,1,m)cin>>a[get(i,j)],num.PB(a[get(i,j)]);
	sort(ALL(num));
	num.erase(unique(ALL(num)),num.end());
	FOR(i,1,n)FOR(j,1,m)a[get(i,j)]=lwb(ALL(num),a[get(i,j)])-num.begin()+1;
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m)v[a[get(i,j)]].PB(MP(i,j));
	}
	FOR(i,1,num.size()){
		ans+=solve(i);
	}
	cout<<ans;
	RE 0;	
}