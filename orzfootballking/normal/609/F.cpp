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
#define lc (x<<1)
#define rc ((x<<1)|1) 
using namespace std;
int p[500005],it[500005];
int a[500005],b[500005],l[500005],sum[500005];
int n,m;
int mini[1100000],id[1100000];
set<P<int,int> > s; 
void build(int x,int l,int r){
	mini[x]=1e18;id[x]=-1;
	if(l==r)RE;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
} 
void pd(int x,int l,int r){
	if(mini[lc]>mini[x]){
		mini[lc]=mini[x];id[lc]=id[x];
	}
	if(mini[rc]>mini[x]){
		mini[rc]=mini[x];id[rc]=id[x];
	}
}
void update(int x,int l,int r,int tl,int tr,int tm,int ti){
	if(tr<tl)RE;
	pd(x,l,r);
	if(l>=tl&&r<=tr){
		if(tm<mini[x]){
			mini[x]=tm;id[x]=ti;
		}
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,tm,ti);
	update(rc,mid+1,r,tl,tr,tm,ti); 
}
int get(int x,int l,int r,int to){
	pd(x,l,r);
	if(l==r)RE id[x];
	int mid=(l+r)>>1;
	if(mid>=to)RE get(lc,l,mid,to);
	else RE get(rc,mid+1,r,to);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>it[i]>>p[i];
	FOR(i,1,m)cin>>a[i]>>l[i],b[i]=a[i];
	sort(b+1,b+m+1);
	build(1,1,m);
	FOR(i,1,n){
		update(1,1,m,lwb(b+1,b+m+1,it[i])-b,upb(b+1,b+m+1,it[i]+p[i])-b-1,it[i],i);
	}
	FOR(i,1,m){
		int t=get(1,1,m,lwb(b+1,b+m+1,a[i])-b);
		if(t==-1){
			s.insert(MP(a[i],i));
		}else{
			p[t]+=l[i];sum[t]++;
			while(!s.empty()){
				set<P<int,int> >::iterator iter =s.lwb(MP(it[t],0ll));
				if(iter==s.end())break;
				P<int,int> now=(*iter);
				if(now.F<=p[t]+it[t]){
					p[t]+=l[now.S];sum[t]++;
					s.erase(iter);
				}else break;
			}
			update(1,1,m,lwb(b+1,b+m+1,it[t])-b,upb(b+1,b+m+1,it[t]+p[t])-b-1,it[t],t);
		}
	}
	FOR(i,1,n){
		cout<<sum[i]<<' '<<p[i]<<'\n';
	}
	RE 0;
}