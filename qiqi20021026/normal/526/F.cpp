#include<bits/stdc++.h>

using namespace std;

#define N 1220000
#define ls (x<<1)
#define rs (x<<1|1)
#define INF 0x3f3f3f3f

int n,x,y,s1[N],s2[N],seg[N][2],tag[N],a[N];
long long ans;

void psd(int x){
	seg[ls][0]+=tag[x]; tag[ls]+=tag[x];
	seg[rs][0]+=tag[x]; tag[rs]+=tag[x];
	tag[x]=0;
}

void mdf(int x,int l,int r,int L,int R,int k){
	if (l>=L&&r<=R){
		seg[x][0]+=k;
		tag[x]+=k;
		return;
	}
	psd(x);
	int mid=(l+r)>>1;
	if (L<=mid) mdf(ls,l,mid,L,R,k);
	if (R>mid) mdf(rs,mid+1,r,L,R,k);
	seg[x][0]=min(seg[ls][0],seg[rs][0]);
	seg[x][1]=0;
	if (seg[ls][0]==seg[x][0]) seg[x][1]+=seg[ls][1];
	if (seg[rs][0]==seg[x][0]) seg[x][1]+=seg[rs][1];
}

void build(int x,int l,int r){
	if (l==r){
		seg[x][0]=INF; seg[x][1]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	seg[x][0]=INF;
	seg[x][1]=seg[ls][1]+seg[rs][1];
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	build(1,1,n);
	for (int i=1,t1=0,t2=0;i<=n;++i){
		mdf(1,1,n,i,i,-INF+i);
		for (;t1&&a[i]>a[s1[t1]];--t1)
			mdf(1,1,n,s1[t1-1]+1,s1[t1],a[i]-a[s1[t1]]);
		s1[++t1]=i;
		for (;t2&&a[i]<a[s2[t2]];--t2)
			mdf(1,1,n,s2[t2-1]+1,s2[t2],-(a[i]-a[s2[t2]]));
		s2[++t2]=i;
		ans+=seg[1][0]==i?seg[1][1]:0;
	}
	printf("%lld\n",ans);
	
	return 0;
}