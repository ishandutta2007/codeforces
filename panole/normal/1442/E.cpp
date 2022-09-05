#include<bits/stdc++.h>
using namespace std;

int n,T,a[200010],x,y,d[200010],q[200010],l,r;
vector<int> v[200010],Q;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]),a[i]=2-a[i],v[i].clear();
		for (int i=1; i<n; i++) 
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y),v[y].push_back(x);
		}
		if (n==1) {puts("1"); continue;}
		int Ans=n;
		for (int col=0; col<2; col++)
		{
			int ans=0;
			for (int i=1; i<=n; i++) d[i]=v[i].size();
			l=1,r=0,Q.clear();
			for (int i=1; i<=n; i++) if (d[i]==1)
			{
				if (a[i]!=col) q[++r]=i;
				else Q.push_back(i);
			}
			//printf("%d\n",Q[0]);
			while (1)
			{
				while (l<=r)
				{
					x=q[l++];
					for (int j=0,sz=v[x].size(); j<sz; j++)
						if ((--d[v[x][j]])==1)
						{
							if (a[v[x][j]]==(col^(ans&1))) Q.push_back(v[x][j]);
							else q[++r]=v[x][j];
						}
				}
				ans++;
				if (r==n) {Ans=min(Ans,ans); break;}
				for (int j=0,sz=Q.size(); j<sz; j++) q[++r]=Q[j];
				Q.clear();
			}
		}
		printf("%d\n",Ans);
	}
	return 0;
}