#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define ls o<<1
#define rs o<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,a[maxn][2],ans;
struct segtree{
	PII mn[maxn];
	int add[maxn];
	inline void pushup(int o){
		mn[o]=min(mn[ls],mn[rs]);
	}
	inline void setadd(int o,int v){
		add[o]+=v;mn[o].fi+=v;
	}
	inline void pushdown(int o){
		if(add[o]){
			setadd(ls,add[o]);
			setadd(rs,add[o]);
			add[o]=0;
		}
	}
	void build(int o,int l,int r){
		if(l==r) return mn[o]=MP(1e9,l),void();
		int mid=(l+r)>>1;
		build(lson);build(rson);
		pushup(o);
	}
	void update(int o,int l,int r,int p,int v){
		if(l==r) return mn[o]=MP(v,l),void();
		pushdown(o);
		int mid=(l+r)>>1;
		if(mid>=p) update(lson,p,v);
		else update(rson,p,v);
		pushup(o);
	}
	void update(int o,int l,int r,int ql,int qr,int v){
		if(ql>qr) return;
		if(l>=ql && r<=qr) return setadd(o,v);
		pushdown(o);
		int mid=(l+r)>>1;
		if(mid>=ql) update(lson,ql,qr,v);
		if(mid<qr) update(rson,ql,qr,v);
		pushup(o);
	}
	PII query(int o,int l,int r,int ql,int qr){
		if(l>=ql && r<=qr) return mn[o];
		pushdown(o);
		int mid=(l+r)>>1;
		if(mid<ql) return query(rson,ql,qr);
		if(mid>=qr) return query(lson,ql,qr);
		return min(query(lson,ql,qr),query(rson,ql,qr));
	}
	int find(int o,int l,int r,int v){
		if(l==r){
			if(mn[o].fi>v) return 0;
			return l;
		}
		pushdown(o);
		int mid=(l+r)>>1;
		if(mn[rs].fi>v) return find(lson,v);
		return find(rson,v);
	}
}s[2],t[2];
struct bit{
	int b[maxn];
	inline void update(int p,int v){
		for(int i=p;i<=n;i+=i&-i) b[i]+=v;
	}
	inline int query(int p){
		int s=0;
		for(int i=p;i;i-=i&-i) s+=b[i];
		return s;
	}
}b[2];
inline int aa(int at,int tp){return at-b[tp].query(at);}
void work(int tp,int l,int r,int wtf=-1){
	if(l>r) return;
	if(wtf==-1){
		if(r==n) wtf=1e9;
		else wtf=t[tp].query(1,1,n,r+1,n).fi;
	}
	PII p=t[tp].query(1,1,n,l,r);
//	printf("tp=%d,l=%d,r=%d,p=(%d,%d)\n",tp,l,r,p.fi,p.se);
	if(p.fi>n || p.fi>=wtf) return;
	int at=p.se;
//	printf("update %d %d %d %d\n",tp,at,a[at][tp],int(aa(a[at][tp],tp^1)-aa(at,tp)));
	s[tp].update(1,1,n,at,aa(a[at][tp],tp^1)-aa(at,tp));
//	assert(aa(a[at][tp],tp^1)-aa(at,tp)==s[tp].query(1,1,n,at,at).fi);
	work(tp,at+1,r,wtf);
}
int main(){
	n=read();
	FOR(_,0,1) s[_].build(1,1,n),t[_].build(1,1,n);
	FOR(i,1,n){
		int x=read();
		a[i][0]=x;a[x][1]=i;
		if(x<i) t[1].update(1,1,n,x,i);
		else t[0].update(1,1,n,i,x);
	}
	FOR(_,0,1) work(_,1,n);
	FOR(i,1,n){
		PII p[2]={s[0].mn[1],s[1].mn[1]};
		int tp=p[1]<p[0],at=p[tp].se,val=a[at][tp];
		ans=max(ans,p[tp].fi);
//		printf("i=%d,tp=%d,at=%d,val=%d,ans=%d\n",i,tp,at,val,ans);
		b[tp].update(at,1);
		b[tp^1].update(val,1);
		s[tp].update(1,1,n,at,1e9);
		t[tp].update(1,1,n,at,1e9);
//		printf("other side update %d %d %d\n",1,t[tp^1].find(1,1,n,at-1),1);
		s[tp^1].update(1,1,n,1,t[tp^1].find(1,1,n,at-1),1);
//		printf("other side update %d %d %d\n",1,n,-1);
		s[tp^1].update(1,1,n,1,n,-1);
//		printf("other side update %d %d %d\n",val,n,1);
		s[tp^1].update(1,1,n,val,n,1);
//		printf("find at %d\n",t[tp].find(1,1,n,val-1));
		work(tp,t[tp].find(1,1,n,val-1)+1,at);
	}
	printf("%d\n",ans);
}