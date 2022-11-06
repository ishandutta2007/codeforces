#pragma GCC optimize(3)
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=600000;
int n,q,l[maxn+10],r[maxn+10],k[maxn+10],cnt,ans,mpbk[maxn+10],s[maxn+10];
struct node{int l,r,v,tag;}a[maxn*4+10];
inline void build(int p,int l,int r){
	a[p].l=l; a[p].r=r; a[p].tag=-1;
	if(l!=r){
		int mid=l+r>>1;
		build(p<<1,l,mid); build(p<<1|1,mid+1,r);
		a[p].v=a[p<<1].v+a[p<<1|1].v;
	}else a[p].v=s[l+1]-s[l];
}
inline void apply(int p,int k){
	a[p].tag=k; a[p].v=(s[a[p].r+1]-s[a[p].l])*k;
}
inline void push(int p){
	if(a[p].tag!=-1){
		apply(p<<1,a[p].tag); apply(p<<1|1,a[p].tag); a[p].tag=-1;
	}
}
inline void change(int p,int l,int r,int k){
	if(a[p].l==l&&a[p].r==r) apply(p,k);
	else{
		int mid=a[p].l+a[p].r>>1; push(p);
		if(r<=mid) change(p<<1,l,r,k);
		else if(l>mid) change(p<<1|1,l,r,k);
		else change(p<<1,l,mid,k),change(p<<1|1,mid+1,r,k);
		a[p].v=a[p<<1].v+a[p<<1|1].v;
	}
}
int main(){
	scanf("%d%d",&n,&q);
	s[++cnt]=1; s[++cnt]=n+1;
	for(int i=1;i<=q;++i){
		scanf("%d%d%d",&l[i],&r[i],&k[i]); ++r[i];
		s[++cnt]=l[i]; s[++cnt]=r[i];
	}
	sort(s+1,s+cnt+1); cnt=unique(s+1,s+cnt+1)-s-1;
	build(1,1,cnt-1);
	for(int i=1;i<=q;++i){
		l[i]=lower_bound(s+1,s+cnt+1,l[i])-s; r[i]=lower_bound(s+1,s+cnt+1,r[i])-s;
		change(1,l[i],r[i]-1,k[i]-1); printf("%d\n",a[1].v);
	}
	return 0;
}