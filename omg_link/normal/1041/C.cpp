#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;
int n,m,d,ansn=1,nxt[MN+5];
struct ques{
	int a,ans,i;
}q[MN+5];
int bin(int k){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(q[mid].a<k) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int getnxt(int p){
	if(q[p].ans==0) return p;
	else return nxt[p]=getnxt(nxt[p]);
}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&q[i].a);
		q[i].i=i;
	}
	for(int i=1;i<=n-1;i++)
		nxt[i]=i+1;
	nxt[n]=1;
	std::sort(q+1,q+1+n,[](ques a,ques b){return a.a<b.a;});
	int p=1,nowm=q[1].a;
	for(int i=1;i<=n;i++){
		q[p].ans=ansn;
		if(i==n) break;
		nowm+=d+1;
		if(nowm>m){
			p=1;
			ansn++;
		}else{
			p=bin(nowm);
			if(p>n){ansn++;p=1;}
		}
		int tp=getnxt(p);
		if(tp<p) ansn++;
		p=tp;
		nowm=q[p].a;
//		printf("%d %d\n",nowm,p);
	}
	std::sort(q+1,q+1+n,[](ques a,ques b){return a.i<b.i;});
	printf("%d\n",ansn);
	for(int i=1;i<=n;i++){
		printf("%d ",q[i].ans);
	}
}