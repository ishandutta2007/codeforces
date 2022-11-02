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
int mod=1e9+7;
int x[2005],y[2005],dis[2005],c[2005],lx,ly,p[2005],r[2005],maxi=1e18;
int lst[2005];// 
V<P<int,int> > g[2005];// 
multiset<int> cg[2005];//y 
V<int> v[2005];//y 
struct node{
	int fi[5000],se[5000],ans[5000],tag[5000],st[5000];
	void pu(int x){
		if(fi[lc]<fi[rc]){
			fi[x]=fi[lc];st[x]=st[lc];
			se[x]=min(se[lc],fi[rc]);
		}else if(fi[lc]>fi[rc]){
			fi[x]=fi[rc];st[x]=st[rc];
			se[x]=min(fi[lc],se[rc]);
		}else{
			fi[x]=fi[lc];st[x]=st[lc]+st[rc];
			se[x]=min(se[lc],se[rc]);
		}
		ans[x]=ans[lc]+ans[rc];
	}
	void beat(int x,int to){
		if(to<=fi[x])RE;
		if(to<se[x]){
			gmax(tag[x],to);
			ans[x]+=st[x]*(to-fi[x]);
			fi[x]=to;
			RE;
		}
		beat(lc,to);
		beat(rc,to);
		pu(x);
	}
	void pd(int x){
		beat(lc,tag[x]);
		beat(rc,tag[x]);
	}
	void build(int x,int l,int r){
		tag[x]=-maxi;
		if(l==r){
			ans[x]=dis[l]*p[l];st[x]=dis[l];
			fi[x]=p[l];se[x]=maxi;
			RE;
		}
		int mid=(l+r)>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		pu(x);
	}
	void update(int x,int l,int r,int tl,int tr,int to){
		if(r<tl||tr<l)RE;
		if(l>=tl&&r<=tr){
			beat(x,to);
			RE;
		}
		pd(x);
		int mid=(l+r)>>1;
		update(lc,l,mid,tl,tr,to);
		update(rc,mid+1,r,tl,tr,to);
		pu(x);
	}
	void update(int l,int r,int x){
		update(1,1,ly,l,r,x);
	}
	void init(){
		build(1,1,ly);
	}
}T;
int ans;
signed main(){
	int k,n,l;
	cin>>n>>k>>l;
	V<int> vx,vy;
	FOR(i,1,n){
		cin>>x[i]>>y[i]>>c[i];x[i]++;y[i]++;
		vx.PB(x[i]);
		vy.PB(y[i]);
	}
	sort(ALL(vx));vx.erase(unique(ALL(vx)),vx.end());lx=vx.size();
	sort(ALL(vy));vy.erase(unique(ALL(vy)),vy.end());ly=vy.size();
	FOR(i,1,n){
		x[i]=lwb(ALL(vx),x[i])-vx.begin()+1;
		y[i]=lwb(ALL(vy),y[i])-vy.begin()+1;
		g[x[i]].PB(MP(y[i],c[i]));
	}
	dis[1]=vy[0];
	FOR(i,2,ly)dis[i]=vy[i-1]-vy[i-2];
	FOR(i,1,lx){
		FOR(j,1,ly)v[j].clear();
		multiset<int> sr;
		FOR(j,1,i){
			for(auto u:g[j]){
				cg[u.S].insert(u.F);
				v[u.F].PB(u.S);
			}
		}
		FOR(j,1,k){
			r[j]=l+1;
			sr.insert(-r[j]);
		}
		for(int j=ly;j>=1;j--){
			for(auto u:v[j]){
				sr.erase(sr.find(-r[u]));
				r[u]=j;
				sr.insert(-r[u]);
			}
			p[j]=-(*sr.begin());
			if(p[j]!=l+1)p[j]=vy[p[j]-1];
		}
		T.init();
		int tr;
		if(i==lx){
			tr=l+1-vx[i-1];
		}else tr=vx[i]-vx[i-1];
		FOR(j,1,i){
			int now=tr*((j==1)?vx[j-1]:(vx[j-1]-vx[j-2]))%mod;
			ans=(ans+(vy.back()*(l+1)-T.ans[1]+mod)%mod*now)%mod;
			for(auto u:g[j]){
				cg[u.S].erase(cg[u.S].find(u.F));
				if(!cg[u.S].count(u.F)){
					auto it=cg[u.S].lwb(u.F);
					int nxt=((it==cg[u.S].end())?(l+1):vy[(*it)-1]);
					if(it==cg[u.S].begin())T.update(1,u.F,nxt);
					else T.update(*(--it)+1,u.F,nxt);
				}
			}
		}
	}
	cout<<ans;
	RE 0;
}