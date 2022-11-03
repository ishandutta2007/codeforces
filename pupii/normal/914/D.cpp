#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int gcd(int a,int b){
	if(!a||!b)return a|b;
	int r=0;
	while((~a&1)&&(~b&1))++r,a>>=1,b>>=1;
	while(~a&1)a>>=1;
	while(~b&1)b>>=1;
	if(a>b)std::swap(a,b);
	return gcd(a,b-a)<<r;
}
int GCD[2000010],A[500010];
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	if(l==r){GCD[x]=A[l];return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	GCD[x]=gcd(GCD[x<<1],GCD[x<<1|1]);
}
void update(int x,int l,int r,int p,int d){
	if(l==r){GCD[x]=d;return;}
	if(p<=mid)update(x<<1,l,mid,p,d);
	else update(x<<1|1,mid+1,r,p,d);
	GCD[x]=gcd(GCD[x<<1],GCD[x<<1|1]);
}
int f;
void query(int x,int l,int r,int L,int R,int o){
	if(L<=l&&r<=R){
		if(GCD[x]%o==0)return;
		if(f){++f;return;}
		if(l==r){++f;return;}
	}
	if(L<=mid)query(x<<1,l,mid,L,R,o);
	if(mid<R)query(x<<1|1,mid+1,r,L,R,o);
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)A[i]=gi();
	build(1,1,n);
	int m=gi(),o,l,r,x;
	while(m--){
		o=gi();
		if(o==1)l=gi(),r=gi(),x=gi(),f=0,query(1,1,n,l,r,x),puts(f<2?"YES":"NO");
		else l=gi(),x=gi(),update(1,1,n,l,x);
	}
	return 0;
}