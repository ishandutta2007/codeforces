#pragma GCC optimize("Ofast","inline","unroll-loops")
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
#define y1 yyyy1111
using namespace std;
int n,a[300005],s[300005],b[300005],k;
int lc[300005],rc[300005],l[300005],r[300005];
P<int,int> p[300005];
void dfs(int x){
	if(b[x])gmin(r[x],b[x]),l[x]=b[x];
	else l[x]=1;
	if(lc[x]){
		r[lc[x]]=r[x];
		dfs(lc[x]);
		gmax(l[x],l[lc[x]]);
	}
	if(rc[x]){
		r[rc[x]]=r[x];
		dfs(rc[x]);
		gmax(l[x],l[rc[x]]);
	}
}
struct seg1{
	int tag[1<<20];
	P<int,int> mini[1<<20];
	void update(int x){
		mini[x]=max(mini[x<<1],mini[x<<1|1]);
	}
	void build(int x,int l,int r){
		tag[x]=0;mini[x]=MP(0,r);
		if(l==r)RE;
		int mid=(l+r)>>1;
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	}
	void pd(int x,int val){
		tag[x]+=val;mini[x].F+=val;
	}
	void pushdown(int x){
		pd(x<<1,tag[x]);pd(x<<1|1,tag[x]);
		tag[x]=0;
	}
	void update(int x,int l,int r,int tl,int tr,int val){
		if(l>=tl&&r<=tr){
			pd(x,val);RE;
		}
		if(l>tr||tl>r)RE;
		int mid=(l+r)>>1;
		pushdown(x);
		update(x<<1,l,mid,tl,tr,val);
		update(x<<1|1,mid+1,r,tl,tr,val);
		update(x);
	}
}T;
V<P<int,int> > op[300005];
int mi[300005],mx[300005];
void update(int x,int y){
	while(x){
		gmax(mx[x],y);
		x-=x&-x;
	}
}
int get(int x){
	int re=1;
	while(x<k){
		gmax(re,mx[x]);
		x+=x&-x;
	}
	RE re;
}
void solve(){
	int Q;
	cin>>n>>Q;
	k=0;
	bool ok=1;
	FOR(i,1,n)cin>>a[i],lc[i]=rc[i]=0;
	FOR(i,1,n){
		cin>>b[i];
		if(!b[i])++k;
	}
	rep(i,1,k){
		cin>>s[i];
	}
	V<int> st;
	FOR(i,1,n){
		while(!st.empty()&&a[st.back()]<a[i]){
			lc[i]=st.back();
			st.pop_back();
		}
		st.PB(i);
	}
	st.clear();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.back()]<a[i]){
			rc[i]=st.back();
			st.pop_back();
		}
		st.PB(i);
	}
	FOR(i,1,n)assert(a[i]>a[lc[i]]&&a[i]>a[rc[i]]);
	int rt=-1;
	FOR(i,1,n)if(a[i]==n)rt=i;
	r[rt]=1e6;
	dfs(rt);
	FOR(i,1,n){
		if(l[i]>r[i]){
			ok=0;
		}
	}
	int len=0;
	FOR(i,1,n)if(!b[i])p[++len]=MP(l[i],r[i]);
	sort(s+1,s+k);
	int t=k-1;
	int ansl=1,ansr=1e6;
	int ff=0;
	FOR(i,1,t)op[i].clear();
	FOR(i,1,k)mi[i]=1e6,mx[i]=1;
	FOR(i,1,len){
		int l=lwb(s+1,s+t+1,p[i].F)-s,r=upb(s+1,s+t+1,p[i].S)-s-1;
//		cout<<l<<' '<<r<<'\n';
		if(l>r){
			if(ff){
				ok=0;
			}else{
				ff=1;
				ansl=p[i].F;ansr=p[i].S;
			}
		}else{
			op[r].PB(MP(l,i));
		}
	}
	if(!ok){
		FOR(i,1,Q){
			int x;
			cin>>x;
			cout<<"NO\n";
		}
		RE ;
	}
	T.build(1,1,t);
	FOR(i,1,t){
		T.update(1,1,t,1,i,-1);
		for(auto u:op[i]){
			T.update(1,1,t,1,u.F,1),gmin(mi[u.F],p[u.S].F);
			update(u.F,p[u.S].S);
		}
		if(T.mini[1].F+ff>=2){
			ok=0;break;
		}
		if(T.mini[1].F==1){
			int t=T.mini[1].S;
			if(t>i)continue;
			gmin(ansr,get(t));
			gmax(ansl,mi[t]);
		}
	}
	if(!ok){
		FOR(i,1,Q){
			int x;
			cin>>x;
			cout<<"NO\n";
		}
		RE ;
	}
	FOR(i,1,Q){
		int x;
		cin>>x;
		if(x>=ansl&&x<=ansr){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}