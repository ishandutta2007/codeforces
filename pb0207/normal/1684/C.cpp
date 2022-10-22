#include<bits/stdc++.h>
using namespace std;

int T;

int n,m;

vector<int>b;

int main()
{
	scanf("%d",&T);
	vector<vector<int> >a;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		a.clear();
		a.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			a[i].resize(m+1);
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		}
		bool fd=0;
		int p=-1,q=-1;
		for(int i=1;i<=n;i++)
		{
			b=a[i];
			sort(b.begin()+1,b.begin()+m+1);
			for(int j=1;j<=m;j++)
			{
				if(b[j]!=a[i][j])
				{
					if(p==-1)
						p=j;
					else if(q==-1)
						q=j;
				}
			}
			if(p!=-1)
			{
				fd=1;
				for(int i=1;i<=n;i++)
				{
					swap(a[i][p],a[i][q]);
				}
				break;
			}
		}
		if(!fd)
		{
			puts("1 1");
		}
		else
		{
			bool ok=1;
			for(int i=1;i<=n;i++)
				for(int j=1;j<m;j++)
					ok&=a[i][j]<=a[i][j+1];
			if(!ok)
				puts("-1");
			else
				printf("%d %d\n",p,q);
		}
	}
}