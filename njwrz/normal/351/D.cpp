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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int a[100005];
int n,m;
P<int,int> p[100005];
struct Bit{
	int a[100005];
	void clear(){
		FILL(a,0);
	}
	void update(int x,int y){
		while(x<=n){
			a[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=a[x];
			x-=x&-x;
		}
		RE re;
	}
	void update(int l,int r,int x){
		update(l,x);
		update(r+1,-x);
	}
	int get(int l,int r){
		RE get(r)-get(l-1);
	}
}T;
int lst[100005],ans[100005];
V<P<int,int> > v[100005];
V<int> it[100005];
int maxi[1<<18],pos[100005],len;
V<P<int,int> > up[1<<18];
void update(int x,int l,int r,int tl,int tr,P<int,int> px){
	if(l>=tl&&r<=tr){
		up[x].PB(px);RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,px);
	update(rc,mid+1,r,tl,tr,px);
}
void solve(int x,int l,int r){
	for(auto u:up[x]){
		T.update(u.F,u.S,1);
	}
	if(l==r){
		for(auto u:v[l]){
			ans[u.S]+=T.get(u.F)==0;
		}
		for(auto u:up[x]){
			T.update(u.F,u.S,-1);
		}
		RE;
	}
	int mid=(l+r)>>1;
	solve(lc,l,mid);
	solve(rc,mid+1,r);
	for(auto u:up[x]){
		T.update(u.F,u.S,-1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i],it[a[i]].PB(i);
	cin>>m;
	FOR(i,1,m){
		cin>>p[i].F>>p[i].S;
		v[p[i].S].PB(MP(p[i].F,i));
	}
	FOR(i,1,n){
		if(lst[a[i]])T.update(lst[a[i]],-1);
		lst[a[i]]=i;
		T.update(i,1);
		for(auto u:v[i]){
			ans[u.S]=T.get(i)-T.get(u.F-1);
		}
	}
	FOR(i,1,100000)if(!it[i].empty()){
		len=0;
		for(auto u:it[i])pos[++len]=u;
		int lst=0,tl=0;
		sort(pos+1,pos+len+1);
		pos[len+1]=n+1;
		FOR(j,1,len){
			if(j>2&&pos[j]-pos[j-1]!=tl){
				lst=pos[j-2];
			}
			tl=pos[j]-pos[j-1];
			update(1,1,n,pos[j],pos[j+1]-1,MP(lst+1,pos[j]));
		}
	}
	T.clear();
	solve(1,1,n);
	FOR(i,1,m)cout<<ans[i]<<'\n';
	RE 0;
}