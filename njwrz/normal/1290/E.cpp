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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
#define lc (x<<1)
#define rc ((x<<1)|1)
int n,a[150005],it[150005];
struct bit{
	int s[150005];
	void init(int n){
		FOR(i,1,n)s[i]=0;
	}
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
}T;
int ans[150005];
int mx[1<<19],cnt[1<<19],mx2[1<<19],sum[1<<19],tag[1<<19],tagmi[1<<19],siz[1<<19];
void update(int x){
	if(mx[lc]>mx[rc]){
		mx[x]=mx[lc];cnt[x]=cnt[lc];
		mx2[x]=max(mx2[lc],mx[rc]);
	}else if(mx[lc]<mx[rc]){
		mx[x]=mx[rc];cnt[x]=cnt[rc];
		mx2[x]=max(mx2[rc],mx[lc]);
	}else {
		mx[x]=mx[lc];cnt[x]=cnt[lc]+cnt[rc];
		mx2[x]=max(mx2[lc],mx2[rc]);
	}
	sum[x]=sum[lc]+sum[rc];siz[x]=siz[lc]+siz[rc];
}
void build(int x,int l,int r){
	tag[x]=0;tagmi[x]=-1;
	if(l==r){
		mx2[x]=-1e18;
		mx[x]=-1e18;sum[x]=0;cnt[x]=0;siz[x]=0;
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(x);
}
void add(int x,int y){
	tag[x]+=y;
	mx[x]+=y;mx2[x]+=y;
	if(tagmi[x]!=-1)tagmi[x]+=y;
	sum[x]+=siz[x]*y;
}
void upmi(int x,int y){
	if(mx[x]<=y)RE;
	sum[x]-=cnt[x]*(mx[x]-y);
	mx[x]=y;tagmi[x]=y;
}
void pushdown(int x){
	if(tag[x]){
		add(lc,tag[x]);
		add(rc,tag[x]);
		tag[x]=0;
	}
	if(tagmi[x]!=-1){
		upmi(lc,tagmi[x]);
		upmi(rc,tagmi[x]);
		tagmi[x]=-1;
	} 
}
void getmi(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr&&mx2[x]<val){
		upmi(x,val);RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	getmi(lc,l,mid,tl,tr,val);
	getmi(rc,mid+1,r,tl,tr,val);
	update(x);
}
void update(int x,int l,int r,int it,int val){
	if(l==r){
		mx[x]=sum[x]=val;
		siz[x]=cnt[x]=1;
		RE;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	if(mid>=it)update(lc,l,mid,it,val);
	else update(rc,mid+1,r,it,val);
	update(x);
}
void add(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		add(x,val);
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	add(lc,l,mid,tl,tr,val);
	add(rc,mid+1,r,tl,tr,val);
	update(x);
}
void solve(){
	FOR(i,1,n)it[a[i]]=i;
	T.init(n);
	build(1,1,n);
	FOR(i,1,n){
		int pos=it[i];
		int now=T.get(pos);
		if(pos>1)getmi(1,1,n,1,pos-1,now);
		update(1,1,n,pos,i);
		if(pos<n)add(1,1,n,pos+1,n,1);
		ans[i]+=sum[1]-i*(i+1)/2;
		T.update(pos,1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	solve();
	reverse(a+1,a+n+1);
	solve();
	FOR(i,1,n)cout<<ans[i]+i<<'\n';
	RE 0;
}