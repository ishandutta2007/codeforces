#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353,INF=1e9;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,a[maxn],add[maxn*4];
struct node{
	int mn,mn2,mnid; 
	node operator+(const node &nd)const{
		node ans;
		if(mn<nd.mn){
			ans.mn=mn;
			ans.mnid=mnid;
			ans.mn2=min(mn2,nd.mn);
		}
		else{
			ans.mn=nd.mn;
			ans.mnid=nd.mnid;
			ans.mn2=min(nd.mn2,mn);
		}
		return ans;
	}
}seg[maxn*4];
inline void pushup(int o){
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
inline void setadd(int o,int v){
	seg[o].mn+=v;
	seg[o].mn2+=v;
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
	if(l==r) return seg[o]=(node){l?INF:0,INF,l},void();
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return setadd(o,v);
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	pushup(o);
}
void update2(int o,int l,int r,int p,int v){
	if(l==r) return seg[o].mn=min(seg[o].mn,v),void();
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid>=p) update2(lson,p,v);
	if(mid<p) update2(rson,p,v);
	pushup(o);
}
node query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return query(lson,ql,qr)+query(rson,ql,qr); 
}
void output(int o,int l,int r){
	if(l==r) return printf("%d ",seg[o].mn),void();
	pushdown(o);
	int mid=(l+r)>>1;
	output(lson);output(rson);
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	build(1,0,n);
//	output(1,0,n);puts("");
	FOR(i,2,n){
		node nd=query(1,0,n,0,n);
		if(a[i]==a[i-1]) update(1,0,n,0,n,1);
		update2(1,0,n,a[i-1],nd.mnid==a[i]?min(nd.mn+1,nd.mn2):nd.mn);
//		output(1,0,n);puts("");
	}
	int ans=query(1,0,n,0,n).mn;
	printf("%d\n",n-ans);
}