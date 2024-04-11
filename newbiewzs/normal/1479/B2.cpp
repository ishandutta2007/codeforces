#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int x=1;
	int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
const int N=2e5+5;
int n,a[N],st[N],top,f[N],g[N],tong[N];
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int minn[N*4];
void build(int u,int l,int r){
	if(l==r){
		minn[u]=1e9;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	minn[u]=1e9;
}
void add(int u,int l,int r,int x,int k){
	if(l==r){
		minn[u]=min(k,minn[u]);
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	else add(rs,mid+1,r,x,k);
	minn[u]=min(minn[ls],minn[rs]);
}
int query(int u,int l,int r,int L,int R){
	if(L>R)return 1e9;
	if(L<0)return 1e9;
	if(R>n)return 1e9;
	if(L<=l && R>=r){
		return minn[u];
	}
	int awa=1e9;
	if(L<=mid)awa=query(ls,l,mid,L,R);
	if(R>mid)awa=min(awa,query(rs,mid+1,r,L,R));
	return awa;
}
int main(){
	n=read();
	if(n==1){
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			st[++top]=a[i];	
		}
	}
	build(1,0,n);
	for(int i=1;i<=top;i++)a[i]=st[i];
	int ans=1e9;
	tong[a[0]]=0;
	add(1,0,n,a[0],0);
	f[1]=1;
	for(int i=2;i<=top;i++){
		f[i]=1e9+8;
		f[i]=min(f[i],min(query(1,0,n,0,a[i]-1),query(1,0,n,a[i]+1,n))+i);
		f[i]=min(f[i],query(1,0,n,a[i],a[i])+i-1);
		add(1,0,n,a[i-1],f[i]-i);
		ans=min(ans,f[i]+top-i);
	}
	cout<<ans;
	return 0;
}