#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,m,k[N],f[N],ans[N],cnt,tot;

bool vis[N];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		cin>>k[i]>>f[i];
	for(int i=1;i<=1000;i++)
	{
		bool tt=true;
		for(int j=1;j<=m;j++)
			if((k[j]-1)/i+1!=f[j])
				tt=false;
		if(tt)
			ans[++cnt]=i;
	}
	for(int i=1;i<=cnt;i++)
		vis[1+(n-1)/ans[i]]=1;
	for(int i=1;i<=1000;++i)
		if(vis[i])
			tot++;
	if(tot!=1)
	{
		cout<<-1;
		exit(0);
	}
	for(int i=1;i<=1000;++i)
		if(vis[i])
			cout<<i;
}