#include<bits/stdc++.h>
using namespace std;

const int N=53;

int n,a[N],b[N];

vector<vector<int> >ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		vector<int>v;
		if(i&1)
		{
			for(int j=1;j<i;j++)
				v.push_back(1);
			for(int j=i;j<=n;j++)
				if(a[j]==i)
					v.push_back(j-i+1),v.push_back(n-j);
			int last=n,now=0;
			for(int j=v.size()-1;j>=0;j--)
			{
				int x=v[j];
				for(int i=last-x+1;i<=last;i++)
					b[++now]=a[i];
				last-=x;
			}	
			for(int j=1;j<=n;j++)
				a[j]=b[j];
		}
		else
		{
			for(int j=n-i+1;j>=1;j--)
				if(a[j]==i)
					v.push_back(j-1),v.push_back(n-i+1-j+1);
			for(int j=n;j>n-i+1;j--)
				v.push_back(1);
			int last=n,now=0;
			for(int j=v.size()-1;j>=0;j--)
			{
				int x=v[j];
				for(int i=last-x+1;i<=last;i++)
					b[++now]=a[i];
				last-=x;
			}	
			for(int j=1;j<=n;j++)
				a[j]=b[j];
		}
		ans.push_back(v);
	}
	if(a[1]!=1)
	{
		vector<int>v; 
		for(int i=1;i<=n;i++)
			v.push_back(1);
		ans.push_back(v);
	}
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			if(ans[i][j]==0)
				ans[i].erase(ans[i].begin()+j);
		if(ans[i].size()==1)
			ans.erase(ans.begin()+i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++,puts(""))
	{
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();j++,putchar(' '))
			printf("%d",ans[i][j]);
	}
}