#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
int n,p[maxn],at[maxn],a[maxn];
ll ans=1e18,mn[maxn*4],add[maxn*4],pre[maxn];
inline void pushup(int o){
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
inline void setadd(int o,ll v){
	mn[o]+=v;
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
	if(l==r) return void(mn[o]=pre[l]);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr,ll v){
	if(l>=ql && r<=qr) return setadd(o,v);
	int mid=(l+r)>>1;
	pushdown(o);
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	pushup(o);
}
int main(){
	n=read();
	FOR(i,1,n) p[i]=read(),at[p[i]]=i;
	FOR(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
	build(1,1,n-1);
	ans=mn[1];
	FOR(i,1,n){
		if(at[i]!=n) update(1,1,n-1,at[i],n-1,-a[at[i]]);
		if(at[i]!=1) update(1,1,n-1,1,at[i]-1,a[at[i]]);
		ans=min(ans,mn[1]);
	}
	printf("%lld\n",ans);
}