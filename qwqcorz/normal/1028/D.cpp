#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
const int p=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
map<int,int>bel;
priority_queue<int,vector<int>,less<int>>q1;
priority_queue<int,vector<int>,greater<int>>q2;
set<int>a;

signed main()
{
	q1.push(0),q2.push(1e9);
	int n=read(),ans=1;
	for (int i=1;i<=n;i++)
	{
		string opt;
		cin>>opt;
		int x=read();
		if (opt=="ADD") a.insert(x);
		else
		{
			if (bel[x]==1)
			{
				while (!a.empty()&&*a.begin()<x)
				{
					bel[*a.begin()]=1;
					q1.push(*a.begin());
					a.erase(*a.begin());
				}
				while (!a.empty()&&*a.rbegin()>x)
				{
					bel[*a.rbegin()]=2;
					q2.push(*a.rbegin());
					a.erase(*a.rbegin());
				}
				if (x==q1.top()) q1.pop();
				else return puts("0"),0;
			}
			else if (bel[x]==2)
			{
				while (!a.empty()&&*a.begin()<x)
				{
					bel[*a.begin()]=1;
					q1.push(*a.begin());
					a.erase(*a.begin());
				}
				while (!a.empty()&&*a.rbegin()>x)
				{
					bel[*a.rbegin()]=2;
					q2.push(*a.rbegin());
					a.erase(*a.rbegin());
				}
				if (x==q2.top()) q2.pop();
				else return puts("0"),0;
			}
			else
			{
				ans=ans*2%p;
				for (int i:a)
				if (i<x) q1.push(i),bel[i]=1;
				else if (i>x) q2.push(i),bel[i]=2;
				a.clear();
			}
		}
	}
	while (!a.empty()&&*a.begin()<q1.top())
	{
		q1.push(*a.begin());
		a.erase(*a.begin());
	}
	while (!a.empty()&&*a.rbegin()>q2.top())
	{
		q2.push(*a.rbegin());
		a.erase(*a.rbegin());
	}
	print(1LL*ans*(a.size()+1)%p);
	
	return 0;
}