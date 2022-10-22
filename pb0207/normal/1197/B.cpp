#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],pos[N];

int c[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int d)
{
	while(x<=n)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=lowbit(x); 
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		add(i,1),pos[a[i]]=i;
	int to=pos[n];
	for(int i=n-1;i>=1;i--)
	{
		int a=min(pos[i],to);
		int b=max(pos[i],to);
		if(query(b)-query(a-1)!=2)
		{
			puts("NO");
			return 0;
		}
		add(pos[i],-1);
	}
	puts("YES");
}