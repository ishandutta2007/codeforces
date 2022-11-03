#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
double p[100010];
struct state{double L,R;}s[400010];
il state operator+(const state&a,const state&b){
	return{
		a.L*b.L/(1-(1-b.L)*a.R),
		b.R+(1-b.R)*a.R/(1-a.R*(1-b.L))*b.L
	};
}
il vd upd(int x,int i){s[x].L=s[x].R=p[i];}
#define mid ((l+r)>>1)
il vd upd(int x){s[x]=s[x<<1]+s[x<<1|1];}
il vd build(int x,int l,int r){
	if(l==r)return upd(x,l);
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	upd(x);
}
il vd update(int x,int l,int r,const int&p){
	if(l==r)return upd(x,l);
	if(p<=mid)update(x<<1,l,mid,p);
	else update(x<<1|1,mid+1,r,p);
	upd(x);
}
il state query(int x,int l,int r,const int&L,const int&R){
	if(L<=l&&r<=R)return s[x];
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
	int n=gi(),a,b,q=gi();
	for(int i=1;i<=n;++i)a=gi(),b=gi(),p[i]=1.0*a/b;
	build(1,1,n);
	int o,l,r;
	while(q--){
		o=gi();
		if(o==1)l=gi(),a=gi(),b=gi(),p[l]=1.0*a/b,update(1,1,n,l);
		else l=gi(),r=gi(),printf("%.10f\n",query(1,1,n,l,r).L);
	}
	return 0;
}