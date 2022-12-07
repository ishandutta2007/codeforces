#include<bits/stdc++.h>
using namespace std;
int fa[5000010];
int get(int i)
{
	return fa[i]==i?i:fa[i]=get(fa[i]);
}
int v1[5000010],v2[5000010],v3[5000010];
int dfs(int i,int n)
{
	//cout<<i<<' '<<n<<endl;
	if(v1[i]!=-1)
		return v1[i];
	v1[i]=-2;
	if(v2[i])
		v1[i]=i;
	for(int j=0;j<n;j++)
		if(i&(1<<j))
		{
			int y=dfs(i^(1<<j),n);
			if(y!=-2)
				v1[i]=y;
		}
		if(v1[i]>=0)
			for(int j=0;j<n;j++)
				if(i&(1<<j))
				{
					if(v1[i^(1<<j)]>=0)
						fa[get(i)]=get(i^(1<<j));
				}
	return v1[i];
}
int getint()
{
	char c;
	int a=0,b=0;
	while(1)
	{
		c=getchar();
		if(c>=48&&c<=57)
			a=a*10+c-48,b=1;
		else
			if(b)
				return a;
	}
}
int num[5000010];
int main()
{
	memset(v1,-1,sizeof(v1));
	int n,m,t1;
	cin>>n>>m;
	int mx=(1<<n)-1;
	for(int i=0;i<(1<<n);i++)
		fa[i]=i;
	for(int i=0;i<m;i++)
	{
		num[i]=getint();
		v2[num[i]]=1;
	}
	for(int i=0;i<m;i++)
	{
		t1=dfs(mx-num[i],n);
	//	cout<<t1<<endl;
		if(t1>=0)
			fa[get(t1)]=get(num[i]);
	}
	int ans=0;
	for(int i=0;i<m;i++)
		if(v3[get(num[i])]==0)
		{
		//	cout<<get(num[i])<<endl;
			ans++;
			v3[get(num[i])]=1;
		}
	cout<<ans;
}