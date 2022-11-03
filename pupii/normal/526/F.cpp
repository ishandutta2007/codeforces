#include<bits/stdc++.h>
typedef long long ll;
#define inf 1000000000000000000ll
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int A[300010];
std::stack<int>smx,smn;
struct data{ll a,b;}seg[1200010];
ll tag[1200010];
data operator+(const data&a,const data&b){
	if(a.a<b.a)return a;
	else if(a.a>b.a)return b;
	return{a.a,a.b+b.b};
}
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	seg[x]={inf,r-l+1};if(l==r)return;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}
void upd(int x,ll d){tag[x]+=d,seg[x].a+=d;}
void down(int x){if(tag[x])upd(x<<1,tag[x]),upd(x<<1|1,tag[x]),tag[x]=0;}
void update(int x,int l,int r,int L,int R,ll d){
	if(L<=l&&r<=R)return upd(x,d);
	down(x);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
data query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return seg[x];
	down(x);
	if(L<=mid)
		if(mid<R)return query(x<<1,l,mid,L,R)+query(x<<1|1,mid+1,r,L,R);
		else return query(x<<1,l,mid,L,R);
	else return query(x<<1|1,mid+1,r,L,R);
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b,d;
	for(int i=1;i<=n;++i)a=gi(),b=gi(),A[a]=b;
	ll ans=0;
	build(1,1,n);
	smx.push(0);smn.push(0);
	for(int i=1;i<=n;++i){
		while(smx.top()&&A[smx.top()]<A[i])d=A[i]-A[smx.top()],smx.pop(),update(1,1,n,smx.top()+1,i-1,d);
		while(smn.top()&&A[smn.top()]>A[i])d=A[smn.top()]-A[i],smn.pop(),update(1,1,n,smn.top()+1,i-1,d);
		if(i>1)update(1,1,n,1,i-1,-1);
		update(1,1,n,i,i,-inf);
		ans+=seg[1].b;
		smx.push(i);smn.push(i);
	}
	printf("%lld\n",ans);
	return 0;
}