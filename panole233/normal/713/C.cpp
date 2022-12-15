#include<bits/stdc++.h>
using namespace std;

int a[3010],n,ans[3010];
long long s1[3001],s2[3010];

void solve(int l,int r,int vl,int vr)
{
	if (l==r) 
	{
		if (a[l]>=vl&&a[l]<=vr) ans[l]=a[l]; else
		if (a[l]<vl) ans[l]=vl; else ans[l]=vr;
		return;
	}
	if (vl==vr)
	{
		for (int i=l; i<=r; i++) ans[i]=vl;
		return;
	}
	int mid=(vl+vr)>>1;
	s1[l-1]=0;
	for (int i=l; i<=r; i++) s1[i]=s1[i-1]+abs(a[i]-mid);
	s2[r+1]=0;
	for (int i=r; i>=l; i--) s2[i]=s2[i+1]+abs(a[i]-mid-1);
	long long mi=1000000000000000000ll,mii;
	for (int i=l-1; i<=r; i++) 
		if (s1[i]+s2[i+1]<mi) mi=s1[i]+s2[i+1],mii=i;
	if (mii!=l-1) solve(l,mii,vl,mid);
	if (mii!=r) solve(mii+1,r,mid+1,vr);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),a[i]-=i;
	solve(1,n,-n-n,1000000000+n);
	long long Ans=0;
	for (int i=1; i<=n; i++) Ans+=abs(ans[i]-a[i]);
	printf("%I64d\n",Ans);
	return 0;
}