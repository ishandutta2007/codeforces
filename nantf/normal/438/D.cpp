#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
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
int n,m,a[maxn],mx[maxn*4];
ll sum[maxn*4];
inline void pushup(int o){
	sum[o]=sum[o<<1]+sum[o<<1|1];
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void build(int o,int l,int r){
	if(l==r) return void(sum[o]=mx[o]=a[l]);
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(o);
}
void modify(int o,int l,int r,int p,int v){
	if(l==r) return void(sum[o]=mx[o]=v);
	int mid=(l+r)>>1;
	if(mid>=p) modify(lson,p,v);
	else modify(rson,p,v);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return sum[o];
	int mid=(l+r)>>1;ll ans=0;
	if(mid>=ql) ans+=query(lson,ql,qr);
	if(mid<qr) ans+=query(rson,ql,qr);
	return ans;
}
void modulo(int o,int l,int r,int ql,int qr,int v){
	if(mx[o]<v) return;
	if(l==r) return void(sum[o]=mx[o]=sum[o]%v);
	int mid=(l+r)>>1;
	if(mid>=ql) modulo(lson,ql,qr,v);
	if(mid<qr) modulo(rson,ql,qr,v);
	pushup(o);
}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	build(1,1,n);
	FOR(i,1,m){
		int op=read(),x=read(),y=read();
		switch(op){
			case 1:printf("%I64d\n",query(1,1,n,x,y));break;
			case 2:modulo(1,1,n,x,y,read());break;
			case 3:modify(1,1,n,x,y);
		}
	}
}