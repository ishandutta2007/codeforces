#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
const double INF=1e18,eps=1e-9;
#define fi first
#define se second
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,q,x,y,a[maxn];
double b[3];
struct node{
	int l,r;
	double mx[3][3];
	node operator+(const node &nd)const{
		node ans;
		ans.l=l;ans.r=nd.r;
		FOR(i,0,2) FOR(j,0,2) ans.mx[i][j]=-INF;
		FOR(i,0,2) FOR(j,0,2) FOR(k,0,2) FOR(l,0,2) if(max(b[j]*y/x+b[k],b[k]*y/x+b[j])<=1+eps){
			ans.mx[i][l]=max(ans.mx[i][l],mx[i][j]+nd.mx[k][l]);
		}
		return ans;
	}
}seg[maxn];
void build(int o,int l,int r){
	if(l==r){
		FOR(i,0,2) FOR(j,0,2) seg[o].mx[i][j]=-INF;
		seg[o].l=seg[o].r=l;
		FOR(i,0,2) seg[o].mx[i][i]=b[i]*a[l]/x;
		return;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
void update(int o,int l,int r,int p){
	if(l==r){
		FOR(i,0,2) seg[o].mx[i][i]=b[i]*a[l]/x;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p);
	else update(rson,p);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
node query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return query(lson,ql,qr)+query(rson,ql,qr);
}
int main(){
	n=read();q=read();
	x=read();y=read();
	if(x>y) swap(x,y);
	b[0]=0,b[1]=1.0*x/y,b[2]=1.0*x/(x+y);
	FOR(i,1,n) a[i]=read();
	build(1,1,n);
	while(q--){
		int op=read(),x=read(),y=read();
		if(op==1) a[x]=y,update(1,1,n,x);
		else{
			node nd=query(1,1,n,x,y);
			double ans=0;
			FOR(i,0,2) FOR(j,0,2) ans=max(ans,nd.mx[i][j]); 
			printf("%.10lf\n",ans);
		}
	}
}