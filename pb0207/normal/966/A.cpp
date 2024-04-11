#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;

set<int>l,e;

int n,m,cl,ce,v,q;

int calc(int x,int y)
{
	return x/y+((x%y)!=0); 
}

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(int i=1;i<=cl;i++)
	{
		int x;
		scanf("%d",&x);
		l.insert(x);
	}
	for(int i=1;i<=ce;i++)
	{
		int x;
		scanf("%d",&x);
		e.insert(x);
	}
	scanf("%d",&q);
	while(q--)
	{
		int ans=0x7fffffff;
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>c)
			swap(a,c);
		if(b>d)
			swap(b,d);
		if(a==c)
		{
			printf("%d\n",d-b);
			continue;
		}
		set<int>::iterator it1,it2;
		if(!l.empty())
		{
			it1=l.lower_bound(b);
			if((*it1)<=d&&(it1)!=l.end())
				ans=min(ans,d-b+c-a);
			else
			{
				it1=l.lower_bound(b);
				if(it1!=l.begin())
				{
					it1--;
					int p=*it1;
					ans=min(ans,d-b+c-a+(b-p)*2);
				}
				it1=l.upper_bound(d);
				if(it1!=l.end())
				{
					int p=*it1;
					ans=min(ans,d-b+c-a+(p-d)*2);
				}
			}
		}
		if(!e.empty())
		{
			it2=e.lower_bound(b);
			if((*it2)<=d&&(it2!=e.end()))
				ans=min(ans,d-b+calc(c-a,v));
			else
			{
				it2=e.lower_bound(b);
				if(it2!=e.begin())
				{
					it2--;
					int p=*it2;
					ans=min(ans,d-b+calc(c-a,v)+(b-p)*2);
				}
				it2=e.upper_bound(d);
				if(it2!=e.end())
				{
					int p=*it2;
					ans=min(ans,d-b+calc(c-a,v)+(p-d)*2);
				}
			}
		}
		printf("%d\n",ans);
	}
}