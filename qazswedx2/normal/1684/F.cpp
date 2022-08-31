#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T,n,m,a[1000005],b[1000005],bt,f[1000005],g[1000005];
vector<int> val[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		bt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[++bt]=a[i];
			f[i]=1e9;
			g[i]=0;
		}
		sort(b+1,b+bt+1);
		bt=unique(b+1,b+bt+1)-b-1;
		for(int i=1;i<=n;i++)
			a[i]=lower_bound(b+1,b+bt+1,a[i])-b;
		for(int i=0;i<=bt;i++)
			val[i].clear();
		for(int i=1;i<=m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			f[r]=min(f[r],l);
		}
		for(int i=n-1;i>0;i--)
			f[i]=min(f[i],f[i+1]);
		int mn=1e9,mx=0,fl=0;
		for(int i=1;i<=n;i++)
		{
			val[a[i]].push_back(i);
			int sz=val[a[i]].size();
			if(f[i]<=i)
			{
				int nw=lower_bound(val[a[i]].begin(),val[a[i]].end(),f[i])-val[a[i]].begin();
				if(nw>=sz-1) continue;
				fl=1;
				mn=min(mn,val[a[i]][nw+1]);
				mx=max(mx,val[a[i]][sz-2]);
			/*	if(nw<sz-2)
				{
				}*/
				g[val[a[i]][nw]]=max(g[val[a[i]][nw]],i);
			}
		}
		if(!fl)
		{
			printf("0\n");
			continue;
		}
	//	printf("mn=%d,mx=%d\n",mn,mx);
		int ans=1e9;
		for(int i=1;i<=min(mn,n);i++)
		{
			ans=min(ans,mx-i+1);
			mx=max(mx,g[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}