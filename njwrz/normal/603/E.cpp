#include<bits/stdc++.h>
#define ll long long
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
int n,m;
int ans[300005];
int fa[100005],siz[100005],odd;
P<P<int,int>,P<int,int> > ed[300005];
P<int,int> hav[300005];
int len;
int get(int x){
	RE (fa[x]==x)?x:(get(fa[x]));
}
void merge(int x,int y){
	x=get(x);y=get(y);
	if(x==y)RE ;
	if(siz[y]>siz[x])swap(x,y);
	fa[y]=x;
	hav[++len]=MP(y,x);
	odd-=siz[x]&1;odd-=siz[y]&1;
	siz[x]+=siz[y];
	odd+=siz[x]&1;
}
int pos;
V<P<int,int> > add[1<<20];
void update(int x,int l,int r,int tl,int tr,P<int,int> ad){
	if(l>=tl&&r<=tr){
		add[x].PB(ad);RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,ad);
	update(rc,mid+1,r,tl,tr,ad);
}
void solve(int x,int l,int r){
	int lst=len;
	for(auto u:add[x])merge(u.F,u.S);
	if(l==r){
		while(pos<m&&odd){
			pos++;
			if(ed[pos].F.S<=l){
				merge(ed[pos].S.F,ed[pos].S.S);
				if(ed[pos].F.S<l)update(1,1,m,ed[pos].F.S,l-1,ed[pos].S);
			}
		}
		if(!odd)ans[l]=ed[pos].F.F;
		else ans[l]=-1;
	}else{
		int mid=(l+r)>>1;
		solve(rc,mid+1,r);solve(lc,l,mid);
	}
	while(len>lst){
		odd-=siz[hav[len].S]&1;
		siz[hav[len].S]-=siz[hav[len].F];
		odd+=siz[hav[len].S]&1;odd+=siz[hav[len].F]&1;
		fa[hav[len].F]=hav[len].F;
		len--;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	odd=n;
	FOR(i,1,m)cin>>ed[i].S.F>>ed[i].S.S>>ed[i].F.F,ed[i].F.S=i;
	sort(ed+1,ed+m+1);
	solve(1,1,m);
	FOR(i,1,m)cout<<ans[i]<<'\n';
	RE 0;
}