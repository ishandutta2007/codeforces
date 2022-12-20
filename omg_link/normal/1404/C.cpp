#include <stdio.h>
#include <algorithm>
#define MN 300000
#define MQ 300000

int n,q,a[MN+5];

struct quest{
	int x,y,id,ans;
}qu[MQ+5];

struct SEG_B{ //answer
	int T[MN*4+5];
	
	void modify(int k,int l,int r,int p){
		if(l==r){
			T[k]++;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid) modify(k<<1,l,mid,p);
		else modify(k<<1|1,mid+1,r,p);
		T[k] = T[k<<1]+T[k<<1|1];
	}
	
	int query(int k,int l,int r,int L,int R){
		if(l==L&&r==R) return T[k];
		int mid=(l+r)>>1;
		if(R<=mid) return query(k<<1,l,mid,L,R);
		if(L>mid) return query(k<<1|1,mid+1,r,L,R);
		return query(k<<1,l,mid,L,mid)+query(k<<1|1,mid+1,r,mid+1,R);
	}
}T2;

struct SEG_A{ //min value
	int T[MN*4+5],tag[MN*4+5];
	
	void update(int k){
		T[k] = std::min(T[k<<1],T[k<<1|1]);
	}
	
	void build(int k,int l,int r){
		if(l==r){
			T[k] = a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid),build(k<<1|1,mid+1,r);
		update(k);
	}
	
	void pushtag(int k,int w){
		T[k] += w;
		tag[k] += w;
	}
	
	void pushdown(int k){
		if(tag[k]){
			pushtag(k<<1,tag[k]);
			pushtag(k<<1|1,tag[k]);
			tag[k] = 0;
		}
	}
	
	void modify(int k,int l,int r,int L,int R,int w){
		if(L>R) return;
		if(l==L&&r==R){
			pushtag(k,w);
			return;
		}
		int mid=(l+r)>>1;
		pushdown(k);
		if(R<=mid) modify(k<<1,l,mid,L,R,w);
		else if(L>mid) modify(k<<1|1,mid+1,r,L,R,w);
		else modify(k<<1,l,mid,L,mid,w),modify(k<<1|1,mid+1,r,mid+1,R,w);
		update(k);
	}
	
	void refresh(int k,int l,int r,int L,int R){
		if(T[k]>0) return;
		if(l==r){
			T2.modify(1,1,n,l);
			modify(1,1,n,r+1,n,-1);
			T[k] = n;
			return;
		}
		int mid=(l+r)>>1;
		pushdown(k);
		if(R<=mid) throw "how did you make this?";
		if(L>mid) refresh(k<<1|1,mid+1,r,L,R);
		else refresh(k<<1,l,mid,L,mid),refresh(k<<1|1,mid+1,r,mid+1,R);
		update(k);
	}
}T1;

int main(){
	//freopen("c.in","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i] = i - a[i];
		if(a[i]<0) a[i] = n+1;
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].x,&qu[i].y);
		qu[i].id = i;
	}
	std::sort(qu+1,qu+1+q,[](const quest &a,const quest &b)->bool{
		return a.x>b.x;
	});
	T1.build(1,1,n);
	for(int i=1,lm=n;i<=q;i++){
		while(lm>qu[i].x){
			T1.refresh(1,1,n,lm,n);
			lm--;
		}
		qu[i].ans = T2.query(1,1,n,qu[i].x+1,n-qu[i].y);
	}
	std::sort(qu+1,qu+1+q,[](const quest &a,const quest &b)->bool{
		return a.id<b.id;
	});
	for(int i=1;i<=q;i++)
		printf("%d\n",qu[i].ans);
}