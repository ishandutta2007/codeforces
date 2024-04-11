#include<bits/stdc++.h>

using namespace std;

#define N 8000000
#define M 500050
#define ls (x<<1)
#define rs (x<<1|1)
#define INF 0x3f3f3f3f

int n,x,mx1[N],mn2[N],tag1[N],tag2[N];

void build1(int x,int l,int r){
	if (l==r){mx1[x]=l; return;}
	int mid=l+(r-l)/2;
	build1(ls,l,mid); build1(rs,mid+1,r);
	mx1[x]=max(mx1[ls],mx1[rs]);
}

void build2(int x,int l,int r){
	if (l==r){mn2[x]=l; return;}
	int mid=l+(r-l)/2;
	build2(ls,l,mid); build2(rs,mid+1,r);
	mn2[x]=min(mn2[ls],mn2[rs]);
}

void psd1(int x){
	mx1[ls]+=tag1[x]; mx1[rs]+=tag1[x];
	tag1[ls]+=tag1[x]; tag1[rs]+=tag1[x];
	tag1[x]=0;
}

void psd2(int x){
	mn2[ls]+=tag2[x]; mn2[rs]+=tag2[x];
	tag2[ls]+=tag2[x]; tag2[rs]+=tag2[x];
	tag2[x]=0;
}

void add(int x,int l,int r,int k){
	if (l>=k){++mx1[x]; ++tag1[x]; return;}
	psd1(x);
	int mid=l+(r-l)/2;
	if (k<=mid) add(ls,l,mid,k);
	add(rs,mid+1,r,k);
	mx1[x]=max(mx1[ls],mx1[rs]);
}

int fd(int x,int l,int r){
	if (l==r) return l;
	psd1(x);
	int mid=l+(r-l)/2;
	if (mx1[ls]>=0) return fd(ls,l,mid);
	return fd(rs,mid+1,r);
}

void mdf(int x,int l,int r,int k){
	if (r<=k){++mn2[x]; ++tag2[x]; return;}
	psd2(x);
	int mid=l+(r-l)/2;
	if (k>mid) mdf(rs,mid+1,r,k);
	mdf(ls,l,mid,k);
	mn2[x]=min(mn2[ls],mn2[rs]);
}

int qry(int x,int l,int r,int k){
	if (l>=k) return mn2[x];
	psd2(x);
	int mid=l+(r-l)/2,ret=INF;
	if (mid>=k) ret=min(ret,qry(ls,l,mid,k));
	ret=min(ret,qry(rs,mid+1,r,k));
	return ret;
}

int main(){
	scanf("%d",&n);
	build1(1,-M,0);
	build2(1,-M,M);
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		if (x<0) add(1,-M,0,x);
		mdf(1,-M,M,x-1);
		x=fd(1,-M,0);
		printf("%d\n",qry(1,-M,M,x));
	}
	
	return 0;
}