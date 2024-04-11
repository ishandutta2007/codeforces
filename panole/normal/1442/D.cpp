#include<bits/stdc++.h>
using namespace std;

int n,k,sz;
vector<int> v[3010];
long long sum[3010];

struct dp{long long f[3010]; void init(){memset(f,0,sizeof(f));}}ans;

dp solve(int l,int r)
{
	dp A; A.init();
	if (l==r)
	{
		for (int i=0,sz=v[l].size(); i<sz&&i<k; i++)
			A.f[i+1]=A.f[i]+v[l][i];
		return A;
	}
	int mid=(l+r)>>1;
	dp L=solve(l,mid),R=solve(mid+1,r);
	for (int i=mid+1; i<=r; i++)
	{
		int sz=v[i].size();
		for (int j=k-sz; j>=0; j--)
			L.f[j+sz]=max(L.f[j+sz],L.f[j]+sum[i]);
	}
	for (int i=l; i<=mid; i++)
	{
		int sz=v[i].size();
		for (int j=k-sz; j>=0; j--)
			R.f[j+sz]=max(R.f[j+sz],R.f[j]+sum[i]);
	}
	for (int i=0; i<=k; i++) A.f[i]=max(L.f[i],R.f[i]);
	return A;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&sz),v[i].resize(sz),sum[i]=0;
		for (int j=0; j<sz; j++) scanf("%d",&v[i][j]),sum[i]+=v[i][j];
	}
	ans=solve(1,n);
	printf("%lld\n",ans.f[k]);
	return 0;
}