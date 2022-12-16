#include <stdio.h>
#include <algorithm>
#define MN 300000
#define MM 1000000

using std::min;
using std::sort;

struct Interval{
	int l,r,w;
	bool operator < (const Interval& that)const{
		return this->w < that.w;
	}
}a[MN+5];

struct Node{
	int min,tag;
}T[MM*4+5];

void pushtag(int k,int w){
	T[k].min += w;
	T[k].tag += w;
}

void pushdown(int k){
	if(T[k].tag){
		pushtag(k<<1,T[k].tag);
		pushtag(k<<1|1,T[k].tag);
		T[k].tag = 0;
	}
}

void modify(int k,int l,int r,int L,int R,int w){
	if(l==L&&r==R){
		pushtag(k,w);
		return;
	}
	int mid = (l+r)>>1;
	pushdown(k);
	if(R<=mid) modify(k<<1,l,mid,L,R,w);
	else if(L>mid) modify(k<<1|1,mid+1,r,L,R,w);
	else modify(k<<1,l,mid,L,mid,w),modify(k<<1|1,mid+1,r,mid+1,R,w);
	T[k].min = min(T[k<<1].min,T[k<<1|1].min);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	m--;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
		a[i].r--;
	}
	sort(a+1,a+1+n);
	int ans = 0x7fffffff;
	for(int l=1,r=1;l<=n;l++){
		while(r<=n&&T[1].min==0){
			modify(1,1,m,a[r].l,a[r].r,1);
			r++;
		}
		if(T[1].min==0) break;
		ans = min(ans,a[r-1].w-a[l].w);
		modify(1,1,m,a[l].l,a[l].r,-1);
	}
	printf("%d\n",ans);
}