#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int N=2e6+1e3+7;

int n,m,s[N],a[N],t,now,x;

bool tag[N];

set<int>S;

void ins(int x)
{
	t=1;
	s[1]++;
	for(int i=19;i>=0;i--)
	{
		if((x>>i)&1) 
			t=t*2+1;
		else 
			t=t*2;
		s[t]++;
	}
}

void query()
{
	t=1;
	now=0;
	for(int i=19;i>=0;i--)
		if(s[t*2+tag[i]]==(1<<i))
			t=t*2+1-tag[i],now=now*2+1;
		else
			t=t*2+tag[i],now=now*2;
	printf("%d\n",now);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (S.find(a[i])!=S.end()) 
			continue;
		ins(a[i]);
		S.insert(a[i]);
	}
	for(int t=1;t<=m;t++)
	{
		scanf("%d",&x);
		for(int i=19;i>=0;i--)
			tag[i]^=(x>>i)&1;
		query();
	}
}