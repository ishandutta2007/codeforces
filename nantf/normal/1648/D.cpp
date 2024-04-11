#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
const ll INF=1e18;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,q,a[maxn],b[maxn],c[maxn],sx[maxn],sy[maxn],tx,ty;
ll pa[maxn],pb[maxn],pc[maxn],wx[maxn],wy[maxn],ans=-INF,F[maxn],G[maxn];
struct segm{
	int l,r,w;
	bool operator<(const segm &s)const{return r<s.r;}
}s[maxn];
struct node{
	ll mn1,mn2,mn;
	node operator+(const node &nd)const{
		node ans;
		ans.mn1=max(mn1,nd.mn1);
		ans.mn2=max(mn2,nd.mn2);
		ans.mn=max({mn,nd.mn,mn1+nd.mn2});
		return ans;
	}
}seg[maxn*2];
void build(int o,int l,int r){
	if(l==r) return seg[o]=(node){wx[l],wy[l],wx[l]+wy[l]},void();
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
node query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return query(lson,ql,qr)+query(rson,ql,qr);
}
struct segtr{
	ll mx[maxn*2],add[maxn*2];
	inline void pushup(int o){
		mx[o]=max(mx[o<<1],mx[o<<1|1]);
	}
	inline void setadd(int o,ll v){
		mx[o]+=v;add[o]+=v;
	}
	inline void pushdown(int o){
		if(add[o]){
			setadd(o<<1,add[o]);
			setadd(o<<1|1,add[o]);
			add[o]=0;
		}
	}
	void build(int o,int l,int r){
		add[o]=0;
		if(l==r) return mx[o]=-INF,void();
		int mid=(l+r)>>1;
		build(lson);build(rson);
		pushup(o); 
	}
	void update(int o,int l,int r,int p,ll v){
		if(l==r) return mx[o]=v,void();
		int mid=(l+r)>>1;
		pushdown(o);
		if(mid>=p) update(lson,p,v);
		else update(rson,p,v);
		pushup(o);
	}
	void update(int o,int l,int r,int ql,int qr,ll v){
		if(ql>qr) return;
		if(l>=ql && r<=qr) return setadd(o,v);
		int mid=(l+r)>>1;
		pushdown(o);
		if(mid>=ql) update(lson,ql,qr,v);
		if(mid<qr) update(rson,ql,qr,v);
		pushup(o);
	}
	ll query(int o,int l,int r,int ql,int qr){
		if(l>=ql && r<=qr) return mx[o];
		int mid=(l+r)>>1;
		pushdown(o);
		if(mid<ql) return query(rson,ql,qr);
		if(mid>=qr) return query(lson,ql,qr);
		return max(query(lson,ql,qr),query(rson,ql,qr));
	}
}sf,sg,sfa,sga;
int main(){
	n=read();q=read();
	FOR(i,1,n) a[i]=read(),pa[i]=pa[i-1]+a[i];
	FOR(i,1,n) b[i]=read(),pb[i]=pb[i-1]+b[i];
	FOR(i,1,n) c[i]=read(),pc[i]=pc[i-1]+c[i];
	FOR(i,1,n) wx[i]=pa[i]-pb[i-1];
	FOR(i,1,n) wy[i]=pb[i]+pc[n]-pc[i-1];
	build(1,1,n);
	FOR(i,1,q){
		int l=read(),r=read(),w=read();
		ans=max(ans,query(1,1,n,l,r).mn-w);
		s[i]=(segm){l,r,w};
	}
	sort(s+1,s+q+1); 
	sf.build(1,1,n);
	sg.build(1,1,n);
	sfa.build(1,1,n);
	sga.build(1,1,n);
	FOR(i,1,n) F[i]=G[i]=-INF;//,printf("wx[%d]=%lld,wy[%d]=%lld\n",i,wx[i],i,wy[i]);
	int cur=1;
	FOR(i,1,q){
		while(cur<=s[i].r){
			int lst=0;
			while(tx && wx[cur]>=wx[sx[tx]]){
				lst=tx==1?1:sx[tx-1];
				sfa.update(1,1,n,lst,sx[tx]-1,-wx[sx[tx]]);
//				printf("f update %d %d %lld\n",lst,sx[tx]-1,-wx[sx[tx]]);
				tx--;
			}
			lst=tx?sx[tx]:1;
			sfa.update(1,1,n,lst,cur-1,wx[cur]);
//			printf("f update %d %d %lld\n",lst,cur-1,wx[cur]);
			sx[++tx]=cur;
			
			while(ty && wy[cur]>=wy[sy[ty]]){
				lst=ty==1?1:sy[ty-1];
				sga.update(1,1,n,lst,sy[ty]-1,-wy[sy[ty]]);
//				printf("g update %d %d %lld\n",lst,sy[ty]-1,-wy[sy[ty]]);
				ty--;
			}
			lst=ty?sy[ty]:1;
			sga.update(1,1,n,lst,cur-1,wy[cur]);
//			printf("g update %d %d %lld\n",lst,cur-1,wy[cur]);
			sy[++ty]=cur;
			cur++;
		}
		ll f=-s[i].w;
		ll g=-s[i].w+query(1,1,n,s[i].l,s[i].r).mn1;
		int lft=max(1,s[i].l-1),rig=s[i].r-1;
		if(lft<=rig){
			f=max(f,sf.query(1,1,n,lft,rig)-s[i].w);
			g=max(g,sg.query(1,1,n,lft,rig)-s[i].w);
			g=max(g,sfa.query(1,1,n,lft,rig)-s[i].w);
			ans=max(ans,sga.query(1,1,n,lft,rig)-s[i].w);
		}
//		printf("mx at %d %d is %lld\n",2,4,sga.query(1,1,n,2,3));
//		printf("(%d,%d,%d),%lld,%lld\n",s[i].l,s[i].r,s[i].w,f,g);
		rig++;
		if(f>F[rig]) sf.update(1,1,n,rig,rig,f-F[rig]),sfa.update(1,1,n,rig,rig,f-F[rig]),F[rig]=f;
		if(g>G[rig]) sg.update(1,1,n,rig,rig,g-G[rig]),sga.update(1,1,n,rig,rig,g-G[rig]),G[rig]=g;
	}
	printf("%lld\n",ans);
}