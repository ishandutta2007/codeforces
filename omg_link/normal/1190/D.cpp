#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;
const int E9=1000000000;
struct node{
	int ls,rs,sm;
}T[MN*32+5];
int gn(){
	static int cnt=1;
	return (++cnt);
}
void modify(int k,int l,int r,int p){
	if(l==r){
		T[k].sm=1;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid){
		if(!T[k].ls)
			T[k].ls=gn();
		modify(T[k].ls,l,mid,p);
	}else{
		if(!T[k].rs)
			T[k].rs=gn();
		modify(T[k].rs,mid+1,r,p);
	}
	T[k].sm=T[T[k].ls].sm+T[T[k].rs].sm;
}
int query(int k,int l,int r,int L,int R){
	if(!k) return 0;
	if(L>R) return 0;
	if(l==L&&r==R) return T[k].sm;
	int mid=(l+r)>>1;
	if(R<=mid) return query(T[k].ls,l,mid,L,R);
	if(L>mid) return query(T[k].rs,mid+1,r,L,R);
	return query(T[k].ls,l,mid,L,mid)+query(T[k].rs,mid+1,r,mid+1,R);
}
int n; LL ans;
struct PT{
	int x,y;
}p[MN+5];
LL calc(LL x){
	return x*(x+1)/2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	std::sort(p+1,p+1+n,[](PT a,PT b)->bool{
		if(a.y==b.y) return a.x<b.x;
		return a.y>b.y;
	});
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j<n&&p[j+1].y==p[i].y) j++;
		for(int k=i;k<=j;k++)
			modify(1,1,E9,p[k].x);
		ans+=calc(query(1,1,E9,1,E9));
		ans-=calc(query(1,1,E9,1,p[i].x-1));
		ans-=calc(query(1,1,E9,p[j].x+1,E9));
		for(int k=i;k<j;k++)
			ans-=calc(query(1,1,E9,p[k].x+1,p[k+1].x-1));
		i=j;
	}
	printf("%lld\n",ans);
}