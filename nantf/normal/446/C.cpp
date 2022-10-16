#include<bits/stdc++.h>
using namespace std;
const int maxn=333333,mod=1000000009;
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
int n,m,a[maxn],fib[maxn],pre[maxn],sum[maxn*4],add1[maxn*4],add2[maxn*4],rfib[maxn];
inline void pushup(int o){
	sum[o]=(sum[o<<1]+sum[o<<1|1])%mod;
}
inline void pushdown(int o,int l,int r){
	if(!add1[o] && !add2[o]) return;
	int mid=(l+r)>>1;
	add1[o<<1]=(add1[o<<1]+add1[o])%mod;
	add1[o<<1|1]=(add1[o<<1|1]+add1[o])%mod;
	add2[o<<1]=(add2[o<<1]+add2[o])%mod;
	add2[o<<1|1]=(add2[o<<1|1]+add2[o])%mod;
	sum[o<<1]=(sum[o<<1]+1ll*(pre[mid+1]-pre[l]+mod)%mod*add1[o]%mod)%mod;
	sum[o<<1]=(sum[o<<1]+1ll*(pre[mid]-pre[l-1]+mod)%mod*add2[o]%mod)%mod;
	sum[o<<1|1]=(sum[o<<1|1]+1ll*(pre[r+1]-pre[mid+1]+mod)%mod*add1[o]%mod)%mod;
	sum[o<<1|1]=(sum[o<<1|1]+1ll*(pre[r]-pre[mid]+mod)%mod*add2[o]%mod)%mod;
	add1[o]=add2[o]=0;
}
void build(int o,int l,int r){
	if(l==r) return void(sum[o]=a[l]%mod);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr,int a1,int a2){
	if(l>=ql && r<=qr){
		add1[o]=(add1[o]+a1)%mod;
		add2[o]=(add2[o]+a2)%mod;
		sum[o]=(sum[o]+1ll*(pre[r+1]-pre[l]+mod)%mod*a1%mod)%mod;
		sum[o]=(sum[o]+1ll*(pre[r]-pre[l-1]+mod)%mod*a2%mod)%mod;
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,a1,a2);
	if(mid<qr) update(rson,ql,qr,a1,a2);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return sum[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1,ans=0;
	if(mid>=ql) ans=(ans+query(lson,ql,qr))%mod;
	if(mid<qr) ans=(ans+query(rson,ql,qr))%mod;
	return ans;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	fib[1]=fib[2]=pre[1]=rfib[1]=1;
	rfib[0]=0;
	pre[2]=2;
	rfib[2]=mod-1;
	FOR(i,3,n+1){
		fib[i]=(fib[i-1]+fib[i-2])%mod;
		pre[i]=(pre[i-1]+fib[i])%mod;
		rfib[i]=(i&1)?fib[i]:mod-fib[i];
	}
	build(1,1,n);
	FOR(i,1,m){
		int op=read(),l=read(),r=read();
		if(op==2) printf("%d\n",query(1,1,n,l,r));
		else update(1,1,n,l,r,rfib[l-1],rfib[l]);
	}
}