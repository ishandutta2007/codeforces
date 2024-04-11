#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int c[N],n,a[N],ans[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int v)
{
	while(x)
	{
		c[x]+=v;
		x-=lowbit(x);
	}
}

int query(int x)
{
	int ret=0;
	while(x<=n)
	{
		ret+=c[x];
		x+=lowbit(x);
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		if(mx<a[i])
			ans[a[i]]--;
		else
		{
			if(query(a[i])==1)
				ans[mx]++;
		}
		add(a[i],1);
		mx=max(mx,a[i]);
	}
	int as=-1e8,pos=1e8;
	for(int i=1;i<=n;i++)
		if(as<ans[i]||(pos>i&&as==ans[i]))
			as=ans[i],pos=i;
	printf("%d",pos);
}