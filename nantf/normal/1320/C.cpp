#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111;
#define int ll
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct weap{
	int a,ca;
	bool operator<(const weap &w)const{return a<w.a;}
}wp[maxn];
struct mons{
	int x,y,z;
	bool operator<(const mons &m)const{return x<m.x;}
}ms[maxn];
int n,m,p,a[maxn],ca[maxn],b[maxn],cb[maxn],x[maxn],y[maxn],z[maxn],tmp[maxn],tl,ans=-1e18,mx[maxn],add[maxn],arr[maxn];
inline void pushup(int o){
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
inline void setadd(int o,int v){
	mx[o]+=v;
	add[o]+=v;
}
inline void pushdown(int o){
	if(add[o]){
		setadd(o<<1,add[o]);
		setadd(o<<1|1,add[o]);
		add[o]=0;
	}
}
void build(int o,int l,int r){
	if(l==r) return void(mx[o]=arr[l]);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return setadd(o,v);
	int mid=(l+r)>>1;
	pushdown(o);
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return mx[o];
	int mid=(l+r)>>1,ans=-1e18;
	pushdown(o);
	if(mid>=ql) ans=max(ans,query(lson,ql,qr));
	if(mid<qr) ans=max(ans,query(rson,ql,qr));
	return ans;
}
signed main(){
	n=read();m=read();p=read();
	FOR(i,1,n) wp[i].a=read(),wp[i].ca=read();
	FOR(i,1,m) tmp[++tl]=b[i]=read(),cb[i]=read();
	FOR(i,1,p) ms[i].x=read(),tmp[++tl]=ms[i].y=read(),ms[i].z=read();
	sort(wp+1,wp+n+1);sort(ms+1,ms+p+1);
	sort(tmp+1,tmp+tl+1);tl=unique(tmp+1,tmp+tl+1)-tmp-1;
	FOR(i,1,n) a[i]=wp[i].a,ca[i]=wp[i].ca;
	FOR(i,1,m) b[i]=lower_bound(tmp+1,tmp+tl+1,b[i])-tmp;
	FOR(i,1,p) x[i]=ms[i].x,y[i]=lower_bound(tmp+1,tmp+tl+1,ms[i].y)-tmp,z[i]=ms[i].z;
	FOR(i,1,tl) arr[i]=-1e18;
	FOR(i,1,m) arr[b[i]]=max(arr[b[i]],-cb[i]);
	build(1,1,tl);
	int cur=1;
	FOR(i,1,n){
		while(cur<=p && x[cur]<a[i]){
			if(y[cur]!=tl) update(1,1,tl,y[cur]+1,tl,z[cur]);
			cur++;
		}
		ans=max(ans,mx[1]-ca[i]);
	}
	printf("%lld\n",ans);
}