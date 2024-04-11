#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T,n,m,p[200010],a[200010];
ll t;
bool check(int x)
{
	ll s=0,now=0;
	int cnt=0,d=a[x];
	for (int i=1;i<=n && cnt<x;i++)
	{
		if (p[i]>d)
		{
			continue;
		}
		if (cnt && cnt%m==0)
		{
			s+=now;
			now=0;
		}
		s+=p[i];
		now+=p[i];
		cnt++;
	}
	//cout<<x<<" "<<d<<" "<<s<<endl;
	return s<=t;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%I64d",&n,&m,&t);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			a[i]=p[i];
		}
		sort(a+1,a+n+1);
		int l=1,r=n,mid;
		while (l<=r)
		{
			mid=(l+r)>>1;
			if (check(mid))
			{
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		if (!r)
		{
			printf("0 %I64d\n",t);
		}
		else
		{
			printf("%d %d\n",r,a[r]);
		}
	}
	return 0;
}