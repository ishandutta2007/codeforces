#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int Inf=(1<<30);
const int Maxn=500000;
ll powmod(ll a,ll b){
	ll res=1;a%=mod;
	assert(b>=0);
	for(;b;b>>=1){
		if(b&1){
			res=res*a%mod;
			a=a*a%mod;
		}
	}
	return res;
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
struct Node{
	ll fg;
	ll val;
}nd[Maxn<<2|5];
void setf(int p,ll v){
	nd[p].fg+=v;
	nd[p].val+=v;
}
void build(int p,int l,int r){
	nd[p].fg=0;
	nd[p].val=1ll<<60;
	if(l==r){
		if(l==0){
			nd[p].val=0;
		}
	}
	else{
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
	}
}
void push(int p){
	if(nd[p].fg){
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
ll query(int p,int l,int r,int x){
	if(l==r){
		return nd[p].val;
	}
	else{
		push(p);
		int md=(l+r)>>1;
		if(x<=md){
			return query(p<<1,l,md,x);
		}
		else{
			return query(p<<1|1,md+1,r,x);
		}
	}
}
void modify(int p,int l,int r,int tl,int tr,ll v){
	if(tl>tr){
		return;
	}
	if(tl==l&&tr==r){
		return setf(p,v);
	}
	else{
		push(p);
		int md=(l+r)>>1;
		if(tr<=md){
			modify(p<<1,l,md,tl,tr,v);
		}
		else if(tl>md){
			modify(p<<1|1,md+1,r,tl,tr,v);
		}
		else{
			modify(p<<1,l,md,tl,md,v);
			modify(p<<1|1,md+1,r,md+1,tr,v);
		}
	}
}
int n,a[Maxn+5],p[Maxn+5],b[Maxn+5],m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	b[m+1]=Inf;
	build(1,0,m);
	for(int i=1;i<=n;i++){
		int j=lower_bound(b+1,b+1+m,a[i])-b;
		if(b[j]==a[i]){
			modify(1,0,m,j+1,m,min(p[i],0));
			ll a=query(1,0,m,j);
			ll x=a+min(p[i],0),y=query(1,0,m,j-1);
			modify(1,0,m,j,j,min(x,y)-a);
			modify(1,0,m,0,j-1,p[i]);
		}
		else{
			modify(1,0,m,j,m,min(p[i],0));
			modify(1,0,m,0,j-1,p[i]);
		}
	}
	ll a=query(1,0,m,m);
	if(a>=(1ll<<55)){
		puts("NO");
	}
	else{
		puts("YES");
		cout<<a<<endl;
	}
	return 0;
}