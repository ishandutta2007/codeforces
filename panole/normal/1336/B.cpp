#include<bits/stdc++.h>
using namespace std;

int n[3],T,x,a[3][100010],y;
set<int> s[3];
set<int>::iterator it;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n[0],&n[1],&n[2]);
		for (int o=0; o<3; o++)
		{
			s[o].clear();
			for (int i=1; i<=n[o]; i++) scanf("%d",&x),s[o].insert(x),a[o][i]=x;
		}
		long long ans=4000000000000000000ll;
		for (int o=0; o<3; o++)
			for (int i=1; i<=n[o]; i++)
			{
				int p=(o==0?1:0),q=(o==2?1:2);
				it=s[p].lower_bound(a[o][i]);
				if (it!=s[p].end())
				{
					x=(*it),it=s[q].upper_bound(a[o][i]);
					if (it!=s[q].begin())
					{
						it--,y=(*it);
						ans=min(ans,1ll*(a[o][i]-x)*(a[o][i]-x)+1ll*(a[o][i]-y)*(a[o][i]-y)+1ll*(x-y)*(x-y));
					}
				}
				swap(p,q);
				it=s[p].lower_bound(a[o][i]);
				if (it!=s[p].end())
				{
					x=(*it),it=s[q].upper_bound(a[o][i]);
					if (it!=s[q].begin())
					{
						it--,y=(*it);
						ans=min(ans,1ll*(a[o][i]-x)*(a[o][i]-x)+1ll*(a[o][i]-y)*(a[o][i]-y)+1ll*(x-y)*(x-y));
					}
				}
			}
		printf("%I64d\n",ans);
	}
	return 0;
}