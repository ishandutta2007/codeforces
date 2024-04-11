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
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,Q;
int root[1<<19];
struct Bit{
	int s[200005];
	void update(int x,int y){
		while(x<=n){
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
}T1,T2;
int tag[1<<19];
P<int,int> maxi[1<<19],m2[1<<19];
struct qu{
	int tap,l,r,t2;
}q[200005];
int Maxi=1e9;
int ch[200005];
void build(int x,int l,int r){
	tag[x]=Maxi;
	if(l==r){
		maxi[x]=MP(Maxi,l);
		m2[x]=MP(0ll,0ll);
		RE ;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	if(maxi[lc]<maxi[rc]){
		maxi[x]=maxi[rc];
		m2[x]=max(m2[rc],maxi[lc]);
	}else{
		maxi[x]=maxi[lc];
		m2[x]=max(m2[lc],maxi[rc]);
	}
}
void pushdown(int x){
	gmin(tag[lc],tag[x]);
	gmin(tag[rc],tag[x]);
	gmin(maxi[lc].F,tag[x]);
	gmin(maxi[rc].F,tag[x]);
	gmin(m2[lc].F,tag[x]);
	gmin(m2[rc].F,tag[x]);
}
void update(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		gmin(tag[x],val);
		gmin(maxi[x].F,val);
		gmin(m2[x].F,val);
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	update(lc,l,mid,tl,tr,val);
	update(rc,mid+1,r,tl,tr,val);
	if(maxi[lc]<maxi[rc]){
		maxi[x]=maxi[rc];
		m2[x]=max(m2[rc],maxi[lc]);
	}else{
		maxi[x]=maxi[lc];
		m2[x]=max(m2[lc],maxi[rc]);
	}
}
P<P<int,int>,P<int,int> > get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		RE MP(maxi[x],m2[x]);
	}
	if(l>tr||tl>r)RE MP(MP(0ll,0ll),MP(0ll,0ll));
	int mid=(l+r)>>1;
	pushdown(x);
	P<P<int,int>,P<int,int> > tx=get(lc,l,mid,tl,tr),ty=get(rc,mid+1,r,tl,tr),re;
	if(tx.F>ty.F){
		re.F=tx.F;
		re.S=max(tx.S,ty.F);
	}else{
		re.F=ty.F;
		re.S=max(ty.S,tx.F);
	}
	RE re;
}
V<int> add[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>Q;
	build(1,1,n);
	FOR(i,1,Q){
		cin>>q[i].tap;
		if(!q[i].tap){
			cin>>q[i].l>>q[i].r>>q[i].t2;
			if(q[i].t2==0){
				update(1,1,n,q[i].l,q[i].r,i);
			}
		}else{
			cin>>q[i].t2;
		}
	}
	FOR(i,1,Q){
		for(auto u:add[i])ch[u]=1;
		if(q[i].tap==0){
			if(q[i].t2==0){
				T1.update(q[i].l,1);
				T1.update(q[i].r+1,-1);
			}else{
				P<P<int,int>,P<int,int> > now=get(1,1,n,q[i].l,q[i].r);
//				cout<<now.S.F<<'\n';
				int ti=max(i+1,now.S.F);
				if(ti<=Q)add[ti].PB(now.F.S);
			}
		}else{
			if(T1.get(q[i].t2)){
				cout<<"NO\n";
			}else if(ch[q[i].t2]){
				cout<<"YES\n";
			}else cout<<"N/A\n";
		}
	} 
	RE 0;
}