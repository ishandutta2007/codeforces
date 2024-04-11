#include<bits/stdc++.h>
using namespace std;

int n,a[100010],m,b[100010],g[100010],l,r,mid,ans;
pair<int,int> A[100010];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1 ;i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=m; i++) scanf("%d%d",&A[i].first,&A[i].second);
	sort(A+1,A+1+m),g[0]=0,b[0]=0;
	for (int i=1; i<=m; i++) b[i]=A[i].first,g[i]=g[i-1]+A[i].second;
	for (int i=1 ;i<=n; i++)
	{
		l=0,r=m;
		while (l<=r)
		{
			mid=(l+r)>>1;
			if (b[mid]<=a[i]) l=mid+1,ans=mid; else r=mid-1;
		}
		printf("%d ",g[ans]);
	}
	return 0;
}