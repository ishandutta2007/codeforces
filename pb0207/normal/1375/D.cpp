#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T;

int n,a[N],vis[N],use[N];

int Mex()
{
	for(int j=0;j<=n;j++)
		vis[j]=0;
	for(int j=1;j<=n;j++)
		vis[a[j]]=1;
	int mex=-1;
	for(int j=0;j<=n;j++)
		if(!vis[j])
		{ 
			mex=j;
			break;
		}
	return mex; 
} 

bool ok()
{
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1])	
			return 0;
	return 1;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			use[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),use[a[i]]++;
		vector<int>v;
		v.clear();
		for(int i=1;i<=n;i++)
			if(use[a[i]]>1)
				use[a[i]]--,a[i]=Mex(),use[a[i]]++,v.push_back(i);
		while(!ok())
		{
			int x=Mex();
			if(x!=n)
				a[x+1]=x,v.push_back(x+1);
			else
				for(int j=1;j<=n;j++)
					if(a[j]!=j-1)
					{
						a[j]=x;
						v.push_back(j);
						break;
					}
		}
		printf("%d\n",v.size());
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
//		puts("");
//		for(int i=1;i<=n;i++)
//			printf("%d ",a[i]);
		puts("");	
	}
}