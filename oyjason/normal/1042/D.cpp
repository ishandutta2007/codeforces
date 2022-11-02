#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
#define maxn 200000000000002ll
using namespace std;
LL read(){
	LL nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,now,sum,rt,cnt,p[M*50],L[M*50],R[M*50],ans;
const LL iv=2;
void ins(LL &x,LL l,LL r,LL pos){
	if(x==0) x=++cnt;
	p[x]++;
	if(l==r) return;
	LL mid=(l+r)/iv;
	if(pos<=mid) ins(L[x],l,mid,pos);
	else ins(R[x],mid+1,r,pos);
}
LL query(LL x,LL l,LL r,LL pos){
	if(r<=pos||!x) return 0;
	if(l>pos) return p[x];
	LL mid=(l+r)/iv;
	return query(L[x],l,mid,pos)+query(R[x],mid+1,r,pos);
}
int main(){
	n=read(),m=read(),ins(rt,0,maxn*2,maxn);
	for(LL i=1;i<=n;i++){
	    now=read(),sum+=now;
	    ans+=query(rt,0,maxn*2,sum-m+maxn);
	    ins(rt,0,maxn*2,sum+maxn);
	}
	printf("%lld\n",ans);
	return 0;
}