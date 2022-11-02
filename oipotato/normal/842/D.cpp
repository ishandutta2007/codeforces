#include <cstdio>
#include <algorithm>
using namespace std;
int go[8000010][2],num[8000010],last,root,tot,n,m,x;
bool vis[300010];
void insert(int x)
{
	int p=root;
	for(int i=20;i>=0;i--)
	{
		if(!go[p][(bool)(x&(1<<i))])
			go[p][(bool)(x&(1<<i))]=++tot;
		num[go[p][(bool)(x&(1<<i))]]++;
		p=go[p][(bool)(x&(1<<i))];
	}
}
int query()
{
	int ans=0,p=root;
	for(int i=20;i>=0;i--)
	{
		int num1=num[go[p][0]],num2=num[go[p][1]];
		if(last&(1<<i))
			swap(num1,num2);
		if(num1<(1<<i))
		{
			ans<<=1;
			p=go[p][(bool)(last&(1<<i))];
		}
		else
		{
			ans<<=1;
			ans++;
			p=go[p][(bool)(!(last&(1<<i)))];
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	root=tot=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(!vis[x])insert(x);
		vis[x]=1;
	}
	last=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		last^=x;
		printf("%d\n",query());
	}
	return 0;
}