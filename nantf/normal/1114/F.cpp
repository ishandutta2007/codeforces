#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=400040,mod=1000000007;
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
int n,q,pri[66],pl,a[maxn],inv[333],f[66],tag1[maxn*4];
ll tag2[maxn*4];
bool vis[333];
void init(){
	FOR(i,2,300){
		if(!vis[i]) pri[++pl]=i;
		for(int j=1;j<=pl && i*pri[j]<=300;j++){
			vis[i*pri[j]]=true;
			if(i%pri[j]==0) break;
		}
	}
	inv[1]=1;
	FOR(i,2,300) inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	FOR(i,1,pl) f[i]=1ll*inv[pri[i]]*(pri[i]-1)%mod;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
struct node{
	int pro;ll has;
}nd[maxn*4];
void pushup(node &o,node l,node r){
	o.has=l.has|r.has;
	o.pro=1ll*l.pro*r.pro%mod;
}
void setmult(int o,int l,int r,int x,ll y){
	tag1[o]=1ll*tag1[o]*x%mod;
	tag2[o]|=y;
	nd[o].pro=1ll*nd[o].pro*qpow(x,r-l+1)%mod;
	nd[o].has|=y;
}
void pushdown(int o,int l,int r){
	if(!tag2[o]) return;
	int mid=(l+r)>>1;
	setmult(lson,tag1[o],tag2[o]);
	setmult(rson,tag1[o],tag2[o]);
	tag1[o]=1;tag2[o]=0;
}
void build(int o,int l,int r){
	tag1[o]=1;tag2[o]=0;
	if(l==r){
		nd[o].pro=a[l];
		FOR(i,1,pl)
			if(a[l]%pri[i]==0) nd[o].has|=1ll<<(i-1);
		return;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(nd[o],nd[o<<1],nd[o<<1|1]);
}
void mult(int o,int l,int r,int ql,int qr,int x,ll y){
	if(l>=ql && r<=qr){
		setmult(o,l,r,x,y);
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(mid>=ql) mult(lson,ql,qr,x,y);
	if(mid<qr) mult(rson,ql,qr,x,y);
	pushup(nd[o],nd[o<<1],nd[o<<1|1]);
}
node query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return nd[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	node ans;
	pushup(ans,query(lson,ql,qr),query(rson,ql,qr));
	return ans;
}
int main(){
	init();
	n=read();q=read();
	FOR(i,1,n) a[i]=read();
	build(1,1,n);
	FOR(i,1,q){
		char op[11];
		scanf("%s",op);
		int l=read(),r=read();
		if(op[0]=='M'){
			int x=read();ll y=0;
			FOR(i,1,pl) if(x%pri[i]==0) y|=1ll<<(i-1);
			mult(1,1,n,l,r,x,y);
		}
		else{
			node ans=query(1,1,n,l,r);
			int s=ans.pro;
			FOR(i,1,pl) if(ans.has&(1ll<<(i-1))) s=1ll*s*f[i]%mod;
			printf("%d\n",s);
		}
	}
}
//CDWDDW