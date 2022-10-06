#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;
int a[MN];
int pre0[MN],pre1[MN];
int suf0[MN],suf1[MN];
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%1d",a+i);
	int a0=n+1,b0=0,a1=n+1,b1=0;
	F(i,1,n){
		if(a[i]==0)a0=min(a0,i),b0=max(b0,i);
		if(a[i]==1)a1=min(a1,i),b1=max(b1,i);
	}
	if(b0-a0+1<=k||b1-a1+1<=k)return puts("tokitsukaze"),0;
	F(i,1,n){
		if(a[i]==0)pre0[i]=i,pre1[i]=pre1[i-1];
		if(a[i]==1)pre1[i]=i,pre0[i]=pre0[i-1];
	}
	dF(i,n,1){
		if(a[i]==0)suf0[i]=i,suf1[i]=suf1[i+1];
		if(a[i]==1)suf1[i]=i,suf0[i]=suf0[i+1];
	}
	F(i,k,n){
		int l=i-k+1,r=i;
		int minpos0,maxpos0,minpos1,maxpos1,ta0,tb0,ta1,tb1;
		minpos0=0,maxpos0=0,minpos1=0,maxpos1=0;
		if(a0<l)minpos0=a0;
		else minpos0=suf0[r+1];
		if(b0>r)maxpos0=b0;
		else maxpos0=pre0[l-1];
		if(a1<l)minpos1=a1;
		else minpos1=suf1[r+1];
		if(b1>r)maxpos1=b1;
		else maxpos1=pre1[l-1];
		// ====
		ta0=l,tb0=r,ta1=n+1,tb1=0;
		if(minpos0)ta0=min(ta0,minpos0);
		if(maxpos0)tb0=max(tb0,maxpos0);
		if(minpos1)ta1=min(ta1,minpos1);
		if(maxpos1)tb1=max(tb1,maxpos1);
	//	printf("0:[%d,%d], 1:[%d,%d]\n",ta0,tb0,ta1,tb1);
		if(tb0-ta0+1>k&&tb1-ta1+1>k)return puts("once again"),0;
		// ====
		ta0=n+1,tb0=0,ta1=l,tb1=r;
		if(minpos0)ta0=min(ta0,minpos0);
		if(maxpos0)tb0=max(tb0,maxpos0);
		if(minpos1)ta1=min(ta1,minpos1);
		if(maxpos1)tb1=max(tb1,maxpos1);
	//	printf("0:[%d,%d], 1:[%d,%d]\n",ta0,tb0,ta1,tb1);
		if(tb0-ta0+1>k&&tb1-ta1+1>k)return puts("once again"),0;
	}
	return puts("quailty"),0;
}