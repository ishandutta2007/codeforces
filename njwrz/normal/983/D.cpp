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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int ans[100005],n;
int lx[100005],rx[100005],ly[100005],ry[100005];
set<int> s[1<<19],s2[1<<19];
V<P<int,int> > op[300005];
V<int> tp[300005];
int L[1<<19],R[1<<19];
int mi[1<<20],mi2[1<<20];
void update(int x){
	mi[x]=min(mi[lc],mi[rc]);
	if(!s[x].empty())gmax(mi[x],*s[x].rbegin());
	mi2[x]=max(mi2[lc],mi2[rc]);
	if(!s2[x].empty())gmax(mi2[x],*s2[x].rbegin());
	if(mi[x]>mi2[x])mi2[x]=0;
}
void build(int x,int l,int r){
	L[x]=l;R[x]=r;
	if(l==r)RE;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void update(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		s2[x].emplace(val);
		s[x].emplace(val);update(x);RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,val);
	update(rc,mid+1,r,tl,tr,val);
	update(x);
}
void erase(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		s2[x].erase(val);
		s[x].erase(val);update(x);RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	erase(lc,l,mid,tl,tr,val);
	erase(rc,mid+1,r,tl,tr,val);
	update(x);
}
void erase2(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		s2[x].erase(val);
		update(x);RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	erase2(lc,l,mid,tl,tr,val);
	erase2(rc,mid+1,r,tl,tr,val);
	update(x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	V<int> vx,vy;
	cin>>n;
	FOR(i,1,n){
		cin>>lx[i]>>ly[i]>>rx[i]>>ry[i];
		vx.PB(lx[i]);
		vx.PB(rx[i]);vx.PB(rx[i]+1);
		vy.PB(ly[i]);
		vy.PB(ry[i]);
	}
	sort(ALL(vx));vx.erase(unique(ALL(vx)),vx.end());
	sort(ALL(vy));vy.erase(unique(ALL(vy)),vy.end());
	FOR(i,1,n){
		lx[i]=lwb(ALL(vx),lx[i])-vx.begin()+1;ly[i]=lwb(ALL(vy),ly[i])-vy.begin()+1;
		rx[i]=lwb(ALL(vx),rx[i])-vx.begin();ry[i]=lwb(ALL(vy),ry[i])-vy.begin();
		op[lx[i]].PB(MP(i,0));
		tp[rx[i]].PB(i);
	}
	int len=vy.size();
	build(1,1,len);
	FOR(i,1,(int)vx.size()+1){
		for(auto u:op[i])update(1,1,len,ly[u.F],ry[u.F],u.F);
		while(mi2[1]){
			ans[mi2[1]]=1;
			erase2(1,1,len,ly[mi2[1]],ry[mi2[1]],mi2[1]);
		}
		for(auto u:tp[i]){
			erase(1,1,len,ly[u],ry[u],u);
		}
	}
	int sum=1;
	FOR(i,1,n)sum+=ans[i];
	cout<<sum;
	RE 0;
}