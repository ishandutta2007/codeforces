#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;

int n,q,a[MN+5];

struct node{
	LL sum;
	int max,min,tag;
}T[MN*4+5];

void pushup(int k){
	T[k].sum = T[k<<1].sum + T[k<<1|1].sum;
	T[k].min = std::min(T[k<<1].min,T[k<<1|1].min);
	T[k].max = std::max(T[k<<1].max,T[k<<1|1].max);
}

void build(int k,int l,int r){
	if(l==r){
		T[k].sum = a[l];
		T[k].max = a[l];
		T[k].min = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}

void pushtag(int k,int l,int r,int w){
	T[k].sum = 1ll*(r-l+1)*w;
	T[k].min = w;
	T[k].max = w;
	T[k].tag = w;
}

void pushdown(int k,int l,int r){
	if(T[k].tag){
		int mid = (l+r)>>1;
		pushtag(k<<1,l,mid,T[k].tag);
		pushtag(k<<1|1,mid+1,r,T[k].tag);
		T[k].tag = 0;
	}
}

int qlast(int k,int l,int r,int vl){
	if(T[k].max<=vl) return 0;
	if(l==r) return l;
	int mid = (l+r)>>1;
	pushdown(k,l,r);
	if(T[k<<1|1].max>vl) return qlast(k<<1|1,mid+1,r,vl);
	else return qlast(k<<1,l,mid,vl);
}

int qnext(int k,int l,int r,int vl){
	if(T[k].min>=vl) return n+1;
	if(l==r) return l;
	int mid = (l+r)>>1;
	pushdown(k,l,r);
	if(T[k<<1].min<vl) return qnext(k<<1,l,mid,vl);
	else return qnext(k<<1|1,mid+1,r,vl);
}

void modify(int k,int l,int r,int L,int R,int w){
	if(L>R) return;
	if(l==L&&r==R){
		pushtag(k,l,r,w);
		return;
	}
	int mid = (l+r)>>1;
	pushdown(k,l,r);
	if(R<=mid) modify(k<<1,l,mid,L,R,w);
	else if(L>mid) modify(k<<1|1,mid+1,r,L,R,w);
	else modify(k<<1,l,mid,L,mid,w),modify(k<<1|1,mid+1,r,mid+1,R,w);
	pushup(k);
}

LL query(int k,int l,int r,int L,int R){
	if(L>R) return 0;
	if(l==L&&r==R) return T[k].sum;
	int mid = (l+r)>>1;
	pushdown(k,l,r);
	if(R<=mid) return query(k<<1,l,mid,L,R);
	if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	return query(k<<1,l,mid,L,mid)+query(k<<1|1,mid+1,r,mid+1,R);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int t,x,y;q--;){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			int l = qlast(1,1,n,y);
			modify(1,1,n,l+1,x,y);
		}
		if(t==2){
			int ans = 0;
			while(x<=n){
				int l=x,r=x,mid;
				for(int i=1;r<n&&query(1,1,n,l,r)<=y;i<<=1)
					r = std::min(r+i,n);
				while(l<=r){
					mid = (l+r)>>1;
					if(query(1,1,n,x,mid)<=y)
						l = mid+1;
					else
						r = mid-1;
				}
				y -= query(1,1,n,x,r);
				ans += r-x+1;
				x = std::max(qnext(1,1,n,y+1),r+1);
			}
			printf("%d\n",ans);
		}
	}
}