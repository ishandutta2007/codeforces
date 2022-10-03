#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MS 1048577
#define ll long long
#define mod 998244353
int n;
int a[MN],lst[MN];
int s1[MN],s2[MN],t1,t2;
ll ans;
int mn[MS],cn[MS],tg[MS],cnt;
inline void p(int i,int x){mn[i]+=x,tg[i]+=x;}
inline void pd(int i){p(i<<1,tg[i]),p(i<<1|1,tg[i]),tg[i]=0;}
void build(int i,int l,int r){
	cn[i]=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}
void mdf(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return p(i,x);
	pd(i);int mid=(l+r)>>1;
	mdf(i<<1,l,mid,a,b,x),mdf(i<<1|1,mid+1,r,a,b,x);
	mn[i]=mn[i<<1],cn[i]=cn[i<<1];
	if(mn[i<<1|1]<mn[i])mn[i]=mn[i<<1|1],cn[i]=0;
	if(mn[i<<1|1]==mn[i])cn[i]+=cn[i<<1|1];
}
void qur(int i,int l,int r,int a,int b){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){if(!mn[i])cnt+=cn[i];return;}
	pd(i);int mid=(l+r)>>1;
	qur(i<<1,l,mid,a,b),qur(i<<1|1,mid+1,r,a,b);
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	build(1,1,n);
	mdf(1,1,n,1,n,1);
	int lb=1;
	F(i,1,n){
		if(lst[a[i]])lb=max(lb,lst[a[i]]+1);
		lst[a[i]]=i;
		mdf(1,1,n,1,i,-1);
		while(t1&&a[s1[t1]]>a[i])mdf(1,1,n,s1[t1-1]+1,s1[t1],a[s1[t1]]-a[i]),--t1;
		while(t2&&a[s2[t2]]<a[i])mdf(1,1,n,s2[t2-1]+1,s2[t2],a[i]-a[s2[t2]]),--t2;
		s1[++t1]=i,s2[++t2]=i;
		cnt=0;
		if(lb<=lst[1])qur(1,1,n,lb,lst[1]);
		ans+=cnt;
	}printf("%lld\n",ans);
	return 0;
}