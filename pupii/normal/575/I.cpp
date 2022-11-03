#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,Q,ls[30000010],rs[30000010],sum[30000010],cnt;
struct Segtree{
	int rt[10010];
#define mid ((l+r)>>1)
	void update(int&x,int l,int r,int L,int R,int d){
		if(!x)x=++cnt;
		if(L<=l&&r<=R){sum[x]+=d;return;}
		if(L<=mid)update(ls[x],l,mid,L,R,d);
		if(mid<R)update(rs[x],mid+1,r,L,R,d);
	}
	int query(int x,int l,int r,int p){
		if(!x||l==r)return sum[x];
		if(p<=mid)return sum[x]+query(ls[x],l,mid,p);
		else return sum[x]+query(rs[x],mid+1,r,p);
	}
	int Query(int x,int y){
		int ret=0;
		while(x<10010)ret+=query(rt[x],1,n,y),x+=x&-x;
		return ret;
	}
	void Update(int x,int l,int r,int d){
		while(x)update(rt[x],1,n,l,r,d),x-=x&-x;
	}
#undef mid
}A,B,C;
int main(){
	n=gi(),Q=gi();
	int d,x,y,l;
	while(Q--){
		if(gi()==1){
			d=gi(),x=gi(),y=gi(),l=gi();
			if(d==1)B.Update(x+y+l,x,x+l,1),A.Update(y-1,x,x+l,-1);
			else if(d==2)A.Update(y,x,x+l,1),C.Update(y-x-l-1+5005,x,x+l,-1);
			else if(d==3)C.Update(y+l-x+5005,x-l,x,1),A.Update(y-1,x-l,x,-1);
			else A.Update(y,x-l,x,1),B.Update(x+y-l-1,x-l,x,-1);
		}else{
			x=gi(),y=gi();
			printf("%d\n",A.Query(y,x)+B.Query(x+y,x)+C.Query(y-x+5005,x));
		}
	}
	return 0;
}